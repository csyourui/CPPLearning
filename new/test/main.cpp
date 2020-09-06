/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-08-25
 */
class AnimalShelf {
 public:
  class Animal {
   public:
    int id;
    int type;
    int time;
    Animal(int id, int type, int time) : id(id), type(type), time(type) {}
  };

  queue<Animal> DogQue;
  queue<Animal> CatQue;
  int totalcount;

  AnimalShelf() { totalcount = 0; }

  void enqueue(vector<int> animal) {
    Animal ani(animal[0], animal[1], totalcount + 1);
    if (animal[1] == 0) {
      CatQue.push(ani);
    } else if (animal[1] == 1) {
      DogQue.push(ani);
    }
  }

  vector<int> dequeueAny() {
    if (CatQue.empty() && DogQue.empty()) {
      return {-1, -1};
    }
    if (CatQue.empty()) {
      return dequeueDog();
    }
    if (DogQue.empty()) {
      return dequeueCat();
    }

    Animal firstcat = CatQue.front();
    Animal firstdog = DogQue.front();
    cout << "first cat: " << firstcat.id << " " << firstcat.type << " "
         << firstcat.time << "\t";
    cout << "first dog: " << firstdog.id << " " << firstdog.type << " "
         << firstdog.time << endl;

    if (firstcat.time < firstdog.time) {
      CatQue.pop();
      return {firstcat.id, firstcat.type};
    } else {
      DogQue.pop();
      return {firstdog.id, firstdog.type};
    }
  }

  vector<int> dequeueDog() {
    if (DogQue.empty()) {
      return {-1, -1};
    }
    Animal firstdog = DogQue.front();
    DogQue.pop();
    return {firstdog.id, firstdog.type};
    ;
  }

  vector<int> dequeueCat() {
    if (CatQue.empty()) {
      return {-1, -1};
    }
    Animal firstcat = CatQue.front();
    CatQue.pop();
    return {firstcat.id, firstcat.type};
  }
};
int main() {
  AnimalShelf* obj = new AnimalShelf();
  obj->enqueue(animal);
  vector<int> param_2 = obj->dequeueAny();
  vector<int> param_3 = obj->dequeueDog();
  vector<int> param_4 = obj->dequeueCat();
}
/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */