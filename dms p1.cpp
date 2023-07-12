
#include<iostream>
using namespace std;

class SET {
  int * arr;
  int n;
  public:
    void setSize() {
      cout << "Enter the size of the set: ";
      cin >> n;
      arr = new int[n];
    }
  void input() {
    cout << "Enter the elements to be entered into the set: " << endl;
    for (int i = 0; i < n; i++) {
      cout << "Enter the " << i + 1 << " element: ";
      cin >> arr[i];
    }
  }
  void unique() {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (arr[i] == arr[j]) {
          for (int k = j; k < n - 1; k++) {
            arr[k] = arr[k + 1];
          }
          n--;
          j--;
        }
      }
    }
  }
  void output() {
    unique();
    cout << "The set is: " << endl;
    cout << "{";
    for (int i = 0; i < n; i++) {
      cout << arr[i];
      if (i != (n - 1)) {
        cout << ", ";
      }
    }
    cout << "}" << endl;
  }
  bool isMember(int x) {
    for (int i = 0; i < n; i++) {
      if (arr[i] == x) {
        return true;
      }
    }
    return false;
  }
  void setUnion(SET b) {
    SET unionSet;
    unionSet.n = n + b.n;
    unionSet.arr = new int[unionSet.n];
    int i = 0, j = 0, k = 0;
    while (i < n && j < b.n) {
      if (arr[i] < b.arr[j]) {
        unionSet.arr[k++] = arr[i++];
      } else if (b.arr[j] < arr[i]) {
        unionSet.arr[k++] = b.arr[j++];
      } else {
        unionSet.arr[k++] = arr[i++];
        j++;
      }
    }
    while (i < n) {
      unionSet.arr[k++] = arr[i++];
    }
    while (j < b.n) {
      unionSet.arr[k++] = b.arr[j++];
    }
    unionSet.n = k;
    unionSet.unique();
    cout << "Union of the sets: {";
    for (int i = 0; i < unionSet.n; i++) {
      if (i == unionSet.n - 1) {
        cout << unionSet.arr[i];
      } else {
        cout << unionSet.arr[i] << ", ";
      }
    }
    cout << "}" << endl;
  }
  void setIntersection(SET b) {
    SET intersectionSet;
    intersectionSet.n = min(n, b.n);
    intersectionSet.arr = new int[intersectionSet.n];
    int i = 0, j = 0, k = 0;
    while (i < n && j < b.n) {
      if (arr[i] < b.arr[j]) {
        i++;
      } else if (b.arr[j] < arr[i]) {
        j++;
      } else {
        intersectionSet.arr[k++] = arr[i++];
        j++;
      }
    }
    intersectionSet.n = k;
    intersectionSet.unique();
    cout << "Intersection of the sets: {";
    for (int i = 0; i < intersectionSet.n; i++) {
      if (i == intersectionSet.n - 1) {
        cout << intersectionSet.arr[i];
      } else {
        cout << intersectionSet.arr[i] << ", ";
      }
    }
    cout << "}" << endl;
  }

  void powerset() {
    int size = 1 << n;  // no. of sets in power set is 2^n by left shift bitwise operator
    for (int i = 0; i < size; i++) {
      cout << "{";
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          if (j != n - 1) {
            cout << arr[j] << ", ";
          } else {
            cout << arr[j];
          }
        }
      }
      cout << "}" << endl;
    }
  }

  bool isSubset(SET b) {
    for (int i = 0; i < b.n; i++) {
      if (!isMember(b.arr[i])) {
        return false;
      }
    }
    return true;
  }

  void complement(SET universalSet) {
    SET complementSet;
    complementSet.n = 0;
    complementSet.arr = new int[universalSet.n];
    for (int i = 0; i < universalSet.n; i++) {
      if (!isMember(universalSet.arr[i])) {
        complementSet.arr[complementSet.n++] = universalSet.arr[i];
      }
    }
    complementSet.unique();
    complementSet.output();
  }
  void setDifference(SET b) {
    SET differenceSet;
    differenceSet.n = n;
    differenceSet.arr = new int[differenceSet.n];
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (!b.isMember(arr[i])) {
        differenceSet.arr[k++] = arr[i];
      }
    }
    differenceSet.n = k;
    differenceSet.unique();
    cout << "Set difference A - B: {";
    for (int i = 0; i < differenceSet.n; i++) {
      if (i == differenceSet.n - 1) {
        cout << differenceSet.arr[i];
      } else {
        cout << differenceSet.arr[i] << ", ";
      }
    }
    cout << "}" << endl;
  }

  void symmetricDifference(SET b) {
    SET symmetricDifferenceSet;
    symmetricDifferenceSet.n = n + b.n;
    symmetricDifferenceSet.arr = new int[symmetricDifferenceSet.n];
    int i = 0, j = 0, k = 0;
    while (i < n && j < b.n) {
      if (arr[i] < b.arr[j]) {
        symmetricDifferenceSet.arr[k++] = arr[i++];
      } else if (b.arr[j] < arr[i]) {
        symmetricDifferenceSet.arr[k++] = b.arr[j++];
      } else {
        i++;
        j++;
      }
    }
    while (i < n) {
      symmetricDifferenceSet.arr[k++] = arr[i++];
    }
    while (j < b.n) {
      symmetricDifferenceSet.arr[k++] = b.arr[j++];
    }
    symmetricDifferenceSet.n = k;
    symmetricDifferenceSet.unique();
    cout << "Symmetric difference of A and B: {";
    for (int i = 0; i < symmetricDifferenceSet.n; i++) {
      if (i == symmetricDifferenceSet.n - 1) {
        cout << symmetricDifferenceSet.arr[i];
      } else {
        cout << symmetricDifferenceSet.arr[i] << ", ";
      }
    }
    cout << "}" << endl;
  }

  void cartesianProduct(SET b) {
    cout << "Cartesian Product of the sets: {";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < b.n; j++) {
        cout << "(" << arr[i] << "," << b.arr[j] << ")";
        if (i != (n - 1) || j != (b.n - 1)) {
          cout << ", ";
        }
      }
    }
    cout << "}" << endl;
  }

};

int main() {



   SET s1, s2, universalSet;
  int choice, element;
  cout<<"This is a menu driven programe."<<endl;
  cout<<"For better functionality please first create Sets s1 and s2"<<endl;

  do {
    cout << "----- MENU -----" << endl;
    cout << "1. Create set s1" << endl;
    cout << "2. Create set s2" << endl;
    cout << "3. Display s1" << endl;
    cout << "4. Display s2" << endl;
    cout << "5. Check Membership for the set s1" << endl;
    cout<<  "6. Check Membership for the set s2" << endl;
    cout << "7. Union of Two Sets" << endl;
    cout << "8. Intersection of Two Sets" << endl;
    cout << "9. Powerset" << endl;
    cout << "10. Check Subset" << endl;
    cout << "11. Complement of a Set" << endl;
    cout << "12. Set Difference" << endl;
    cout<<  "13. Symmetric Difference" <<endl;
    cout<<  "14. Cartesian Product"<<endl;
    cout << "15. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
      case 1:



        s1.setSize();

        s1.input();
        s1.unique();

        break;

      case 2:



        s2.setSize();

        s2.input();
        s2.unique();


        break;

      case 3:
        s1.output();
        break;

      case 4:
        s2.output();
        break;

      case 5:

        cout << "Enter the element to check whether the lement is present or not: ";
        cin >> element;
        if (s1.isMember(element)) {
          cout << element << " is a member of the set s1." << endl;
        } else {
          cout << element << " is not a member of the set s1." << endl;
        }
        break;

      case 6:
        cout << "Enter the element to check whether the element is present or not: ";
        cin >> element;
        if (s2.isMember(element)) {
          cout << element << " is a member of the set s2." << endl;
        } else {
          cout << element << " is not a member of the set s2." << endl;
        }

      case 7:

        cout<<"Union of the set s1 and s2:";
        s1.setUnion(s2);
        break;

      case 8:

        cout<<"Intersection of s1 ans s2:";
        s1.setIntersection(s2);
        break;

      case 9:

       cout<<"Powerset of the s1:";
        s1.powerset();
        break;

      case 10:


        if (s1.isSubset(s2)) {
          cout << "The set is a subset of the given set." << endl;
        } else {
          cout << "The set is not a subset of the given set." << endl;
        }
        break;

      case 11:

        cout<<"For Universal set"<<endl;

        universalSet.setSize();
        universalSet.input();
        universalSet.unique();
        cout<<"Complement of the set s1:"<<endl;
        s1.complement(universalSet);
        break;

      case 12:

        cout<<"Set Difference between s1 and s2:";
        s1.setDifference(s2);
        break;

      case 13:
          cout<<"Symmetric difference of s1 and s2:";
          s1.symmetricDifference(s2);
          break;

      case 14:

       cout<<endl; cout<<"Cartesian Product of s1 and s2"<<endl;
       s1.cartesianProduct(s2);
       break;


      case 15:
        cout << "Exiting..." << endl;
        break;

      default:
        cout << "Invalid Choice. Please try again." << endl;
    }
  } while (choice != 15);

return 0 ;
}
