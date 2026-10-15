#include <iostream>
#include <string>
#include <vector>
using namespace std;
class GameCharacter {
public:
    string name;
    int hp;
    int level;

    GameCharacter(string n, int h, int l) {
       
        this->name = n;
        this->hp = h;
        this->level = l;
    }
    
        // 受到傷害
        void damage(int value)
        {
            hp = hp - value;

            if (hp < 0) {
                hp = 0;
            }
        }
    
// 回復生命值
void heal(int value)
{
    hp = hp + value;
    if (hp > 100)
    { hp = 100; }
}
// 升級
void levelUp()
{
    level++;
    hp = 100;
}
// 顯示角色資料
void show()
{
    cout << "name:" << name << "\n" << "hp:" << hp << "\n" << "level:" << level << "\n";
}
};

int main()
{
    int count;
    cout << "腳色人數:";
    cin >> count;
    vector<GameCharacter> characters;
    // 建立角色
    for (int i = 0; i < count; i++) {
        string name;
        int hp, level;

        cout << "\n請輸入角色 " << i + 1 << " 的名稱：";
        cin >> name;

        cout << "請輸入血量：";
        cin >> hp;

        cout << "請輸入等級：";
        cin >> level;
        characters.push_back(GameCharacter(name, hp, level));
    }int a;
    do {
        cout << "====" << "選單" << "=====" << "\n";
        cout << "1.扣寫" << "\n";
        cout << "2.回血" << "\n";
        cout << "3.升級" << "\n";
        cout << "4.角色資料" << "\n";
        cout << "0.結束" << "\n";
        
        cout << "輸入指令";
        cin >> a;
        int ind, value;
        if (a >= 1 && a <= 4) {
            cout << "選腳色(1~" << count << "):";
            cin >> ind;
            ind--;
        }
        

       
        switch (a) {
        case 1:
            cout << "輸入傷害直:";
            cin >> value;
            characters[ind].damage(value);
            characters[ind].show();
            break;
        case 2:
            cout << "輸入回血直:";
            cin >> value;
            characters[ind].heal(value);
            characters[ind].show();
            break;
        case 3:
            cout << "輸入升級直:";
            cin >> value;
            characters[ind].levelUp();
            characters[ind].show();
            break;
        case 4:
            characters[ind].show();
            break;
        case 0:
            cout << "結束程式\n";
            break;
        
        }

        } while (a != 0);
        return 0;
}
        
    
   

