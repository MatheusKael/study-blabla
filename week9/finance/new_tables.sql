CREATE TABLE stock_purchases(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    price NUMERIC NOT NULL,
    year INTEGER NOT NULL,
    month INTEGER NOT NULL,
    day INTEGER NOT NULL,
    user_id INTEGER NOT NULL,
    stock_id INTEGER NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (stock_id) REFERENCES stocks(id)
);