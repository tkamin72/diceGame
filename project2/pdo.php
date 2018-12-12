<?php
require_once ('../../creds.php');

$dsn = "mysql:host=".DB_HOST.";dbname=".DB_NAME.";charset=$charset";
$opt =
[
PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
PDO::ATTR_EMULATE_PREPARES => false,
];
$dsn = "mysql:host=".DB_HOST.";dbname=".DB_NAME.";charset=$charset";

$pdo = new PDO($dsn, DB_USER, DB_PASS, $opt);