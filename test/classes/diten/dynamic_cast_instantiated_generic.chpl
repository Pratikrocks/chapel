class C {
  type t;
  var a, b: t;
}

proc main {
  var c = new unmanaged C(int, 1, 2);
  var o: object = c;
  writeln((o:c.type).a);
  delete c;
}
