class Foo {
  type t;

  proc init(type t) {
    this.t = t;
  }
}

var foo = new unmanaged Foo(t=int);
writeln(foo.type: string);
delete foo;
