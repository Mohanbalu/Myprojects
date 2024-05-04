function validateForm(event) {
    event.preventDefault(); 
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    if (username === "user" && password === "pass") {
        window.location.href = "interests.html";
    } else {
        alert("Incorrect username or password. Please try again.");
    }
}