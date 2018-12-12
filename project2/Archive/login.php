<?php
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

//Login part that sets the cookies after its validated
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
	require('loginfunction.phtml');
	require ('mysqlilogin.phtml');
	
	
	list ($check, $data) = check_login($dbc,$_POST['email'],$_POST['pass']);
	
	   if ($check) {
	   setcookie ('user_id', $data['user_id']);
	   setcookie ('first_name', $data['first_name']);
	   setcookie ('priv', $data['priv']);
	   redirect_user('index.php?page=loggedin');
	   }
	   else {
		   $errors = $data;
	   }
	   mysqli_close($dbc);
}
	   include('login.phtml');
	   
	   ?>