CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    birth DATE,
    phone VARCHAR(15),
    street VARCHAR(100),
    number VARCHAR(10),
    neighborhood VARCHAR(50),
    complement VARCHAR(100)
);