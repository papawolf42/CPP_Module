class A {
 public:
  int a;
};

class B {
 public:
  int a;
};

class C : public B, public A {
 public:
  int c;
};

int main() {
	C c;
	c.a = 3;
}
