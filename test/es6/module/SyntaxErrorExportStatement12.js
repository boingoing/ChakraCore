// Syntax error if export statement is in any block

function foo() { }
{ export { foo }; }
