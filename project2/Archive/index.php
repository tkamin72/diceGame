<?php
require ('pdo.php');

//session arrays acting similar to objects //

$_SESSION['User'] = array(
    array('user_id'),
    array('first'),
    array('last'),
    array('email'),
    array('address'),
    array('city'),
    array('state'),
    array('zip'),

);
$_SESSION['Cart'] = array(

    array('cart_id'),
    array('cartProductID')
);

if (!isset($_SESSION['userSignedIn'])) {
    $_SESSION['userSignedIn']=false;
}
/**
 * Trevor Kamin
 * CIS 222 Project 1
 *
 * This website was used as my PHP w/ MYSQL course with professor Banks. It will
 *be used in a production for Fancie That Candles. This is a complete online
 * store, and will be fully functional when completed.
 *
 * PHP version 5.4.45
 *
 * @package    Fancie That Candles
 * @author     Trevor Kamin
 * @copyright  2018 Fancie That Candles
 * @version    12/09/2018
 * @link       https://cislinux.hfcc.edu/~tkamin/project2/index.php
 */
session_start();

//creats the pdo connection including creds file path



if(isset($_POST['action'] )){



    $call = $_POST['action'];



    switch ($call){



        case  'signup':
            require 'encrypt.php';
            $valid=false;
            if (isset($_POST['submit'],$_POST['firstname'], $_POST['lastname'], $_POST['pass'], $_POST['email'],
                $_POST['addy'], $_POST['city'], $_POST['zip'], $_POST['State'])) {
                //echo "hi:";



                    //if the duplicate email test passes then insert the user into the table //



                        //this var will carry the user id to pass into the cart that is craeted for them On signup//
                        $userID=null;

                        //this query inserts the new customer//
                        $insert_into_table = 'INSERT INTO users VALUES(NULL ,"'.$_POST['firstname'].'", "'.$_POST['lastname'].'","'. $_POST['email'].'","'. zCrypt($_POST['pass']).'",
                    "'.$_POST['addy'].'","'. $_POST['city'].'","'. $_POST['State'].'","'. $_POST['zip'].'",null )';


                        $_SESSION['User']['first'] [] =$_POST['firstname'];
                        $_SESSION['User']['last'] [] =$_POST['lastname'];
                        $_SESSION['User']['email'] [] =$_POST['email'];
                        //skip password cuz we dont need it //
                        $_SESSION['User']['address'] [] =$_POST['addy'];
                        $_SESSION['User']['city'] [] =$_POST['city'];
                        $_SESSION['User']['state'] [] =$_POST['State'];
                        $_SESSION['User']['zip'] [] =$_POST['zip'];


                        $_SESSION['userSignedIn']=true;


                        unset($_POST['pass']); // unset the password //

                        $pdo->query($insert_into_table);//executing query to insert new user after validation //



                       // --            LINKING CART TO USER            --//

                        $getUid = 'SELECT user_id FROM users WHERE email = "'. $_POST ['email'].'";';

                        $getTheID = $pdo->query($getUid);//Execute the query

                        //loop through table to reach result //
                        while ($row = $getTheID->fetch(PDO::FETCH_NUM)){

                            $userID = $row[0];//fetch the user id
                            $_SESSION['User']['user_id'] [] =$row[0];//setting user id
                            break;
                        }//end of while loop

                        //query to create--> change these when we fix the table //
                        /*$create_Cart_For_User= 'INSERT INTO cart(null ,'.$_SESSION['User']['user_id'][0].',null);';

                        $pdo->query($create_Cart_For_User);//execute query for new cart //

                        $getCartID = 'SELECT  cart_id FROM cart WHERE user_id = '.$_SESSION['User']['user_id'] ['user_id'];



                        $row= $pdo->query($getCartID);//get cart id and cart items id

                        while ($rowA = $row->fetch(PDO::FETCH_NUM)){

                             $_SESSION['Cart']['cart_id'][] = $rowA[0] ;//assign cart id to Session array
                             //$_SESSION['Cart']['cartProductID'][] = $rowA[1];//assign cartItems id's to Cart
                        }*/

                        header('https://cislinux.hfcc.edu/~tkamin/project2/index.php');

            }//end of big if


            break;


        case 'login'  :

            require 'encrypt.php';



//Creating a query to grab all fields from the customer table

            //checking  login form and button  clicked //
            if (isset($_POST['submit'], $_POST['email'], $_POST['pass'])) {

                $checkForLogin = 'SELECT * FROM users';

                $email = $pdo->query($checkForLogin);//execute query to check if email is registered

                var_dump($_POST['email']);
                var_dump($_POST['pass']);
                while ($data = $email->fetch(PDO::FETCH_NUM)){


                        if ($_POST['email']==$data[3]){
                            //compare the hashes, never use the actual values //
                            if (zCrypt($_POST['pass'])==$data[4]){
                                $_SESSION['User']['user_id'] [] =$data[0];
                                $_SESSION['User']['first'] [] =$data[1];
                                $_SESSION['User']['last'] [] =$data[2];
                                $_SESSION['User']['email'] [] =$data[3];
                                //skip password cuz we dont need it //
                                $_SESSION['User']['address'] [] =$data[5];
                                $_SESSION['User']['city'] [] =$data[6];
                                $_SESSION['User']['state'] [] =$data[7];
                                $_SESSION['User']['zip'] [] =$data[8];
                                $_SESSION['userSignedIn']=true;

                                break;


                                //this query will get the cart by searching for user id in the cart table //
                                //$getTheCart='SELECT cart_id,cart_items_id FROM cart WHERE user_id ='.$data[0];

                                //$imOutOfnAMES = $pdo->query($getTheCart);

                                //assigning cart info to session cart //
                               // while ($rowCheck = $imOutOfnAMES->fetch(PDO::FETCH_NUM) ){

                                   // $_SESSION['Cart'] ['cart_id'] [] = $rowCheck[0];


                                   // $_SESSION['Cart']['cartProductID'][] = $rowCheck[1];

                                //}


                            }//2nd if
                            else{}

                            break;
                        }
                        else{}


                }



            }

            break;//end of login case




    case 'signout':

        if (isset($_POST['submit']) && $_SESSION['userSignedIn']){


            unset($_SESSION['User']); // unset customer session var //
            unset($_SESSION['Cart']);
            $_SESSION['userSignedIn'] = false; // set signed in to false value //
            //echo 'You have been signed out';
            header("https://cislinux.hfcc.edu/~tkamin/project_2/index.php");

        }


        break;

        /*
    case 'signuph':




        require 'encrypt.php';



        $new_user = new Customer;//new customer object//

        if (isset($_POST['signupDone'],$_POST['firstName'],$_POST['lastName'],$_POST['bday'],
            $_POST['email'],$_POST['phone'],$_POST['city'],$_POST['street'],$_POST['state'],
            $_POST['uname'],$_POST['psw'],$_POST['pswR'])){

            $quryToCheck = 'SELECT * FROM Customers;';

            $stmt = $pdo->query($quryToCheck);


//username's are unique. no duplicates are allowed.
// could maybe use some js to highlight boxes if
// entered username is taken.This validates-->
            $exists= false;
            while ($row = $stmt->fetch(PDO::FETCH_NUM)) {if ($row[3] === $_POST['uname']){$exists=true;break;}}


            $new_user = new Customer;//new customer object//

            //if passwords dont match //
            if (encryptThis($_POST['psw']) !== encryptThis($_POST['pswR'])){

                $_POST['psw']  = null;
                $_POST['pswR'] = null;

                echo'Passwords dont match';

                header("Location : includes/home.phtml");

            }//end of if
            else if ($exists){
                $_POST['psw']  = null;
                $_POST['pswR'] = null;
                echo 'User name taken';

                header("Location : includes/home.phtml");

            }

            else{
                //could probably these and possibly make them a constant so they really wont change //
                $createCustomerQuery = 'INSERT INTO Customers (user_id,customer_FName, customer_LName,
                                cutomer_UserName, customer_Password, customer_PhoneNum,
                                customer_Notes, customer_BirthDate, Email, Address,
                                 fk_customer_order_id, fk_customer_cart_id)VALUES (null,"'.$_POST['firstName'].'","'.$_POST['lastName'].'",
                                 "'.$_POST['uname'].'","'.encryptThis($_POST['psw']).'","'.$_POST['phone'].'",null,"'.$_POST['bday'].'","'.$_POST['email'].'",
                                 "'.$_POST['street'].$_POST['state'].$_POST['city'].'",null,null);';

                $_POST['psw']  = null;
                $_POST['pswR'] = null;//null out passwords :) //

                $pdo->query($createCustomerQuery); //add to database

                //get the row of data from the database for the newly registered customer//
                $qryToGet= 'SELECT * FROM Customers WHERE cutomer_UserName = "'.$_POST['uname'].'"';

                $got = $pdo->query($qryToGet);//execute query to check

                while ($row2 = $got->fetch(PDO::FETCH_NUM)){




                    //Global session array will be carrying All object and user account data back to index
                    $_SESSION['Customer']= array($row2[0],$row2[1],$row2[2],$row2[3],$row2[5],$row2[6],$row2[7],$row2[8],$row2[9],$row2[10],$row2[11]);

                    $_SESSION['userSignedIn'] = true;//user officially signed up and IS logged in //

                }//end of while loop row2



                //TODO : make a cart items table that takes in products and their information that links to a users cart

                $createCart = 'INSERT INTO Cart(`fk_cart_user_id`,`cart_purchased`,`cart_quantity`)
                       VALUES("'.$_SESSION['Customer'][0].'",null,null);';

                $pdo->query($createCart); // execute query to dbs //

                //look for the new users cart //
                $checkCart = 'SELECT * FROM Cart WHERE fk_cart_user_id = "'.$_SESSION['Customer'][0].'"';


                $exec = $pdo->query($checkCart); // exec query that looks for users cart

                while ($cart = $exec->fetch(PDO::FETCH_NUM)){

                    $_SESSION['Cart'] = array($cart[0],$cart[1],$cart[2],$cart[3]);



                }

                //linking cart to customer //
                $assignCartIdToCustomer = 'UPDATE Customers SET fk_customer_cart_id = "'.$_SESSION['Cart'][0].'"
                                           WHERE user_id = "'.$_SESSION['Customer'][0].'";';

                $pdo->query($assignCartIdToCustomer);



                //Redirect back to home page as a logged in customer //
                header("Location: https://cislinux.hfcc.edu/~fsobh/CIS222P1/index.php");





            }//end of else


        }

        break;
    case 'add':

        if (isset($_POST['ll'])) {

            $checkWhichProduct = 'SELECT product_id FROM Products';
            $var = $pdo->query($checkWhichProduct);

            while ($id = $var->fetch(PDO::FETCH_NUM)) {

                if ($_POST['ll'] == $id[0]) {
                    $actual = $id[0];
                    break;
                }
            }
            $quryToInsert = 'INSERT INTO Cart_Items (fk_cart_id,fk_product_id)VALUES ("' . $_SESSION['Cart'][0] . '"
                   ,"' . $actual . '" )'; //inserting

            $pdo->query($quryToInsert); //exec query
            $_SESSION['product_ids'] [] = $actual; //add product id to session array var to move to cart object in header page //
        }

        if (isset($_POST['productPage'])) {

            $checkWhichProduct = 'SELECT product_id FROM Products';
            $var = $pdo->query($checkWhichProduct);

            while ($id = $var->fetch(PDO::FETCH_NUM)) {

                if ($_POST['productPage'] == $id[0]) {
                    $actuall = $id[0];
                    break;
                }
            }
            $_SESSION['productPage_id']=$actuall;
            header("Location: https://cislinux.hfcc.edu/~fsobh/CIS222P1/index.php?page=pp");

        }

        break;
    case 'del':

        if (isset($_POST['trash'])){

            $checkWhichProduct = 'SELECT product_id FROM Products';
            $varx = $pdo->query($checkWhichProduct);

            while ($id = $varx->fetch(PDO::FETCH_NUM)) {

                if ($_POST['trash'] == $id[0]) {
                    $actualll = $id[0];
                    $removeThatShiz = 'DELETE FROM Cart_Items WHERE fk_cart_id = "'.$_SESSION['Cart'][0].'" AND fk_product_id= "'.$actualll.'"';
                    $pdo->query($removeThatShiz);

                    //array keys function to remove the products
                    foreach (array_keys($_SESSION['product_ids'], $actualll, true) as $key) {
                        unset($_SESSION['product_ids'][$key]);
                    }
                    header("Location: https://cislinux.hfcc.edu/~fsobh/CIS222P1/index.php");
                    break;
                }
            }
        }

    case 'contact':

        if(isset($_POST['submit'])){

            $qryVar = 'UPDATE Customers SET customer_Notes="'.$_POST['subject'].'" WHERE user_id = "'.$_SESSION['Customer'][0].'"';
            $pdo->query($qryVar);
        }*/


    }//end of switch


}//end of if isset(action)//





//Requires for the driver files 
require('header.phtml');

if(isset($_GET['page']) && $_GET['page'] == 'contact' )
{
    require( 'contact.phtml' );
		   
}
elseif(isset($_GET['page']) && $_GET['page'] == 'products' )
{
	require( 'products.phtml' );
    
}
elseif(isset($_GET['details']) && $_GET['details'] !=  null ) {
	require( 'product.phtml' );
}
elseif(isset($_GET['page']) && $_GET['page'] == 'signup' )
{
	require( 'signup.phtml' );
    
}
elseif(isset($_GET['page']) && $_GET['page'] == 'login' ) {
	require( 'login.phtml' );
}
elseif(isset($_GET['page']) && $_GET['page'] == 'comments' ) {
	require( 'comments.phtml' );
}
elseif(isset($_GET['page']) && $_GET['page'] == 'signupresponse' ) {
	require( 'signupresponse.phtml' );
}
elseif(isset($_GET['page']) && $_GET['page'] == 'search' ) {
	require( 'search.phtml' );
}
elseif(isset($_GET['page']) && $_GET['page'] == 'loggedin' ) {
	require( 'loggedin.phtml' );
}
elseif(isset($_GET['page']) && $_GET['page'] == 'loggedout' ) {
	require( 'logout.phtml' );
}
else if(isset($_GET['page']) && $_GET['page'] == 'cart' )
{
    require( 'cart.phtml' );
}
else if(isset($_GET['page']) && $_GET['page'] == 'checkout' )
{
    require( 'checkout.phtml' );
}
elseif(isset($_GET['page']) && $_GET['page'] == 'admin' ) {
	require( 'admin.phtml' );
}
else {
	require( 'home.phtml' );
}


require( 'footer.phtml' );
