// Syntax error if export statement is in arrow function

function foo() { }
() => { export { foo }; }
