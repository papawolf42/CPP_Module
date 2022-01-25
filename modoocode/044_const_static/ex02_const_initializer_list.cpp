#include <iostream>

class Marine {
	int hp;					// 마린 체력
	int coord_x, coord_y;	// 마린 위치
	// int damage;				// 공격력
	const int default_damage;	// 기본 공격력
	bool is_dead;

	public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}
Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {}
Marine::Marine(int x, int y, int default_damage) : hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false) {}
void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Marine marine1(2, 3, 10);
	Marine marine2(3, 5, 10);

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}
