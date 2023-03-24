CREATE TABLE houses_assignments (
    id INTEGER,
    student_id INTEGER,
    house_id INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(house_id) REFERENCES houses(id),
    FOREIGN KEY(student_id) REFERENCES students(id),
);
CREATE TABLE houses (
    id INTEGER,
    house_name TEXT,
    PRIMARY KEY(id),
);