var csv = require('csv');
var fs = require('fs');
csv.parse(fs.readFileSync('sample.csv'), function(err, data) {
  input = data;
  loadProgram(data)
});

function loadProgram(input) {
  console.log(input[0]);
}
