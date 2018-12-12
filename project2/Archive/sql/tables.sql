/*
    MySQL statements to create the tables
 */
CREATE TABLE IF NOT EXISTS products(
    prod_id BIGINT(11) UNSIGNED AUTO_INCREMENT,
    prod_name VARCHAR(60),
    prod_descript TEXT,
    prod_price DECIMAL(10,2),
    prod_stock INT(10),
    link VARCHAR (200),
    PRIMARY KEY (prod_id)
);

CREATE TABLE IF NOT EXISTS Orders(
    order_id BIGINT(11) UNSIGNED AUTO_INCREMENT,
    cust_id BIGINT(32),
    order_total DECIMAL(10,2),
    order_date DATETIME,
    shipped_status VARCHAR(4),
    tax DECIMAL(10,2),
    PRIMARY KEY (order_id)
);

CREATE TABLE IF NOT EXISTS cart(
    cart_id BIGINT(11) UNSIGNED AUTO_INCREMENT,
    user_id VARCHAR(32),
    prod_name VARCHAR(32),
    quantity VARCHAR(100),
    prod_stock SMALLINT(10),
    cookie VARCHAR(100),
    PRIMARY KEY (cart_id)
);

CREATE TABLE IF NOT EXISTS users(
  user_id BIGINT(11) UNSIGNED AUTO_INCREMENT,
  first_name VARCHAR(60),
  last_name VARCHAR(60),
  email VARCHAR(100),
  password VARCHAR(100),
  address VARCHAR(50),
  city VARCHAR(50),
  state VARCHAR(25),
  zip VARCHAR(10),
  priv INT(2),
  PRIMARY KEY (user_id)
);


/*
    MySQL statement to fill the products table
 */
INSERT INTO products (prod_id, prod_name, prod_descript,prod_price, prod_stock, link)
              VALUES (NULL, 'Toaster Strudel', 'Scent of freshly picked blueberries, juicy blackberries, sweet raspberries and notes of fresh cream.', 12.00, 10, 'productimages/toaster_strudel.jpg'),
                     (NULL, 'Mango Papaya Tango', 'Scent of slices of sweet mango and papaya.', 12.00, 10, 'productimages/mango_papaya.jpg'),
                     (NULL, 'Cherry Lemonade', 'Scent of cherry, lemon and lime mingled with light vanilla accents.', 12.00, 10, 'productimages/cherry_lemonade.jpg'),
                     (NULL, 'Apple Crumb Muffin', 'Scent of apples, cinnamon, nutmeg and clove with an undertone of creamy coconut and sweet vanilla.', 12.00, 10, 'productimages/apple_crumb.jpg'),
                     (NULL, 'Pumpkin Latte`', 'Scent of vanilla mixed with a sweet pumpkin accord.', 12.00, 10, 'productimages/pumpkin_latte.jpg');
