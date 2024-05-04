<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "usersdata";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $username = $_POST["username"];
    $phnCode = $_POST["phnCode"];
    $phn = $_POST["phn"];
    $password = $_POST["password"];
    $dob = $_POST["dob"];
    $gender = $_POST["gender"];

   /* echo '$username';
    echo '$phnCode';
    echo '$phn';
    echo '$password';
    echo '$dob';
    echo '$gender';*/


    $sql = "INSERT INTO users (username, phone_code, phone_number, password, dob, gender) 
            VALUES ('$username', '$phnCode', '$phn', '$password', '$dob', '$gender')";

    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

$conn->close();
?>
