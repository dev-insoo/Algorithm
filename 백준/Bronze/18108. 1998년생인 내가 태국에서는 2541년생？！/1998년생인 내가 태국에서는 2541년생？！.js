let fs = require("fs");
// let input = fs.readFileSync("input.txt").toString().split(" ");
// let input = fs.readFileSync("input.txt").toString().trim();
let input = fs.readFileSync("/dev/stdin").toString().split(" ")

let year = Number(input[0])

console.log(year-543)
