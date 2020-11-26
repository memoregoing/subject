//
// Created by namhyung kim on 2020/11/25.
//

#ifndef CPP_VICTIM_HPP
#define CPP_VICTIM_HPP

# include <iostream>
# include <string>

//CPP가 처음이라면 ? C에서 구조체를 사용 했던 것처럼 구조체와 비슷하지만 구조체에 메서드(함수)가 포함 될 수 있는 형태라고 보면 됩니다.

class Victim {
protected:
    Victim();

    std::string name;
public:
    Victim(std::string const &name); //래퍼런스 변수를 받는 생성자 래퍼런스 변수란?
    // 참조형 함수 매개변수는 인수의 별칭으로 사용되며 복사본이 만들어지지 않아요. C언어에서 *를 전달 할때와 비슷하다고 보시면 됩니다. 하지만 값으로 바로 사용
    // 가능하다는게 다른 점이라고 하면 할 수 있습니다.
    Victim(const Victim& other); //복사 생성자
    // 복사 생성자는 클레스의 인스턴스를 받아 새로운 인스턴스를 만들 때 사용 되요!! strcpy랑 비슷하다고 보면 됩니다. 메모리를 공유하지 않고 복사해요!
    virtual ~Victim(); // 소멸자 C언어에서 프리와 비슷하다고 보시면 되요!!
    // virtual이란 키워드가 있는데 이를 통해 상속되더라도 자식이 프리되지 않아 메모리 누수가 생기지 않게 하기 위함이에요!!

    Victim &operator=(const Victim& other);

    std::string const &getName(void) const;
    virtual void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &out, Victim const &sorcerer);
// 연산자 오버로딩으로 << 이 연산자는 클레스 밖에서 오버로딩 해야 한다고 해요 매개변수로 첫번째는 out를 받고 두번째로 필요한 인수를 받습니다.

#endif //CPP_VICTIM_HPP
