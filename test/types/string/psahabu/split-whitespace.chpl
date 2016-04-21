var spaces = "The quick brown fox jumps over the lazy dog";
var tabs = "The\tquick\tbrown\tfox\tjumps";
var newLines = "The\nquick\nbrown\nfox\njumps";
var returns = "The\rquick\rbrown\rfox\rjumps";
var bigSpace = "The quick brown           fox   jumps";
var whitespace = " \t\r\n";
var empty = "";

proc test(s, testname) {
  writeln(testname, ': "', s, '"');

  write("no limit: [ ");
  for x in s.split() {
    write('"', x, '"', " ");
  }
  writeln("]");

  write("limit 3: [ ");
  for x in s.split(maxsplit=3) {
    write('"', x, '"', " ");
  }
  writeln("]");

  write("limit 1: [ ");
  for x in s.split(maxsplit=1) {
    write('"', x, '"', " ");
  }
  writeln("]");

  writeln("\n");
}

test(spaces, "spaces");
test(tabs, "tabs");
test(newLines, "new lines");
test(returns, "returns");
test(bigSpace, "several spaces");
test(whitespace, "whitespace");
test(empty, "empty");
