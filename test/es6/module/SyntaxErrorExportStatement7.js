// Syntax error if export statement is in a nested function

function foo() { 
    export default function() { }
}
