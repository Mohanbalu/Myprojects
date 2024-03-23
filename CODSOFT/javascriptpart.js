let expression = '';

function appendNumber(number) {
  expression += number;
  document.getElementById('display').value = expression;
}

function operation(operator) {
  expression += operator;
  document.getElementById('display').value = expression;
}

function clearDisplay() {
  expression = '';
  document.getElementById('display').value = expression;
}

function calculate() {
  try {
    const result = eval(expression);
    document.getElementById('display').value = result;
  } catch (error) {
    document.getElementById('display').value = 'Error';
  }
}
