<?php
session_start();

$username = "root";
$localhost    = "127.0.0.1";
$dbname = "register";
$errors = array(); 

$db = mysqli_connect(localhost, 'root', '', 'register');

if (isset($_POST['reg_user'])) {

    $username = mysqli_real_escape_string($db, $_POST['username']);
    $password_1 = mysqli_real_escape_string($db, $_POST['password']);
    $confirmPassword = mysqli_real_escape_string($db, $_POST['confirmPass']);
    $dob = $_POST['dob']; // The value is a date, you might want to validate it further
    $gender = mysqli_real_escape_string($db, $_POST['gender']);
    $otp = intval($_POST['otp']); // Convert to integer
    $captcha = mysqli_real_escape_string($db, $_POST['captcha']);
    
    if (empty($username)) {
        array_push($errors, "Username is required");
    }
    if (empty($password_1)) {
        array_push($errors, "Password is required");
    }
    if ($password_1 !== $confirmPassword) {
        array_push($errors, "The two passwords do not match");
    }
    if (empty($dob)) {
        array_push($errors, "Date of Birth is required");
    }
    if (empty($gender)) {
        array_push($errors, "Gender is required");
    }
    if (empty($otp)) {
        array_push($errors, "OTP is required");
    }
    if (empty($captcha)) {
        array_push($errors, "Captcha is required");
    }
    
    $user_check_query = "SELECT * FROM users WHERE username=? LIMIT 1";
    $stmt = mysqli_prepare($db, $user_check_query);
    mysqli_stmt_bind_param($stmt, "s", $username);
    mysqli_stmt_execute($stmt);
    $result = mysqli_stmt_get_result($stmt);
    $user = mysqli_fetch_assoc($result);
    
    if ($user) { 
        array_push($errors, "Username already exists");
    }
    
    mysqli_stmt_close($stmt);
  
    if (count($errors) == 0) {
        $hashed_password = password_hash($password_1, PASSWORD_DEFAULT);
    
        $query = "INSERT INTO users (username, password, dob, gender, otp, captcha) 
                  VALUES('$username', '$hashed_password', '$dob', '$gender', '$otp', '$captcha')";
        mysqli_query($db, $query);
    
        $_SESSION['username'] = $username;
        $_SESSION['success'] = "You are now logged in";
        header('location: index.php');
    }
    

// LOGIN USER
if (isset($_POST['login_user'])) {
    $username = mysqli_real_escape_string($db, $_POST['username']);
    $password = mysqli_real_escape_string($db, $_POST['password']);

    if (empty($username)) {
        array_push($errors, "Username is required");
    }
    if (empty($password)) {
        array_push($errors, "Password is required");
    }

    if (count($errors) == 0) {
        $query = "SELECT * FROM users WHERE username=?";
        $stmt = mysqli_prepare($db, $query);
        mysqli_stmt_bind_param($stmt, "s", $username);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);

        if ($row = mysqli_fetch_assoc($result)) {
            $hashed_password = $row['password'];

            if (password_verify($password, $hashed_password)) {
                $_SESSION['username'] = $username;
                $_SESSION['success'] = "You are now logged in";
                header('location: index.php');
            } else {
                array_push($errors, "Wrong username/password combination");
            }
        } else {
            array_push($errors, "User not found");
        }

        mysqli_stmt_close($stmt);
    }
}
?>