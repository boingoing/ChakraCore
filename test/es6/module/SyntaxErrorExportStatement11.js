// Syntax error if export statement is in try catch statement


function foo() { }
try { export { foo }; } catch(e) { }
