CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id),
    FOREIGN KEY(house) REFERENCES houses(id)
);

CREATE TABLE houses {
    id INTEGER,
    house_name TEXT,
    PRIMARY KEY(id),
}