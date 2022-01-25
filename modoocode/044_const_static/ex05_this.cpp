// 자기 자신을 가리키는 포인터 this
#include <iostream>

class Marine {
	static int total_marine_num;
	const static int i = 0;

	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage;

	public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack();
	// void be_attacked(int damage_earn);
	Marine& be_attacked(int damage_earn);// 기존에는 void 였는데, 리턴값으로 레퍼런스를 쓴다...?
	void move(int x, int y);

	void show_status();
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0), is_dead(false), default_damage(5) {
	total_marine_num++;
}
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), is_dead(false), default_damage(5) {
	total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage)
	: hp(50),
	coord_x(x),
	coord_y(y),
	is_dead(false),
	default_damage(default_damage) {
	total_marine_num++;
}
void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {// return 타입이 객체의 레퍼런스
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;

	return *this;// 자신의 주소값으 ㄹ리턴...?
}
void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
	Marine marine3(10, 10, 4);
	marine3.show_total_marine();
}

int main() {
	Marine marine1(2, 3, 5);
	marine1.show_total_marine();

	Marine marine2(3, 5, 10);
	marine2.show_total_marine();

	create_marine();

	// std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
	std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
	// marine2.be_attacked(marine1.attack());
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());// 마린2가 마린1에게 공격당함. 리턴된 마린2가 다시 마린1에게 공격당함.

	marine1.show_status();
	marine2.show_status();
}
