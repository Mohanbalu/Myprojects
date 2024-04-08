function txt(value) {
    var display = document.getElementById("display");
    display.textContent += value;
}

function operand(value) {
    var display = document.getElementById("display");

    switch(value) {
        case "%":
            display.textContent += "/100";
            break;
        case "1/x":
            var x = prompt("Enter the value of x:");
            if (x !== null) {
                display.textContent = 1 / parseFloat(x);
            }
            break;
        case "1/x^2":
            var x = prompt("Enter the value of x:");
            if (x !== null) {
                display.textContent = 1 / Math.pow(parseFloat(x), 2);
            }
            break;
        case "√x":
            var x = prompt("Enter the value of x:");
            if (x !== null) {
                display.textContent = Math.sqrt(parseFloat(x));
            }
            break;
        case "=":
            try {
                display.textContent = eval(display.textContent);
            } catch (error) {
                display.textContent = "Error";
            }
            break;
        default:
            break;
    }
}
