import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session.get("user_id")

    cash = db.execute(f"SELECT cash FROM users WHERE id = {user_id};")
    user_stocks = db.execute(
        f"SELECT user_id, count(stock_id) AS shares_owned, * FROM stock_purchases AS sp LEFT JOIN stocks AS sts ON sts.id = sp.stock_id GROUP BY sp.user_id HAVING sp.user_id = {user_id};")

    total = 0

    for user_stock in user_stocks:
        user_stock["price"] = lookup(user_stock["symbol"])["price"]
        user_stock["total_value"] = user_stock["price"] * user_stock["shares_owned"]
        total += user_stock["total_value"]

    return render_template("index.html", user_stocks=user_stocks, balance=cash[0]["cash"], grand_total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        stock = lookup(symbol)

        if stock is None:
            return apology("TODO")

        stock_name = stock["name"]
        stock_price = stock["price"]
        stock_symbol = stock["symbol"]

        stock_found = db.execute(
            f"SELECT * FROM stocks WHERE name LIKE '{stock_name}';")

        if len(stock_found) == 0:
            db.execute(
                f"INSERT INTO stocks (name, price, symbol) VALUES ('{stock_name}', {stock_price}, '{stock_symbol}');")
            stock_found = db.execute(
                f"SELECT * FROM stocks WHERE name LIKE '{stock_name}';")

        user_id = session.get("user_id")
        user = db.execute(f"SELECT * FROM users WHERE id = {user_id}")
        stock_id = stock_found[0]["id"]

        updated_cash = user[0]["cash"] - stock_price

        year = datetime.date.today().year
        month = datetime.date.today().month
        day = datetime.date.today().day

        db.execute(
            f"UPDATE users AS user SET cash = {updated_cash} FROM users WHERE user.id = {user_id};")

        columns = "price, year, month, day, user_id, stock_id"
        values = f"{stock_price}, {year}, {month}, {day}, '{user_id}', '{stock_id}'"

        db.execute(
            f"INSERT INTO stock_purchases ({columns}) VALUES ({values});")

        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")
        stock = lookup(symbol)

        return render_template("quoted.html", stock=stock)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":

        username = request.form.get("username")
        password = request.form.get("password")

        if username is None or password is None:
            return apology("TODO")

        hash = generate_password_hash(password)

        db.execute(
            f"INSERT INTO users (username, hash) VALUES ('{username}', '{hash}');")
        user = db.execute(
            f"SELECT * FROM users WHERE username = '{username}';")

        return user
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
