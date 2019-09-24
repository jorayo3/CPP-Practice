#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <stack>
#include <memory>
using namespace std;

struct Item {
    string tag;
    map<string, string> items;
    map<string, Item*> mp;

    Item (string name) {
        tag = name;
    }
    Item() {}
};

void getInput(istream& input, Item* tag) {
    string attribute, value;
    getline(input, attribute, ' ');
    getline(input, value, '"');
    getline(input, value, '"');
    tag->items.insert (pair<string, string> (attribute, value));
    if (input.peek() == ' ') {
        input.ignore(255, ' ');
        getInput(input, tag);
    }
    // cout << "tag: " << tag->tag << ", attribute: " << attribute << ", value: " << value << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int inputs, queries;
    
    if (!(cin >> inputs >> queries)) {
        cout << "Invalid inputs or queries." << endl;
        return -1;
    }

    cin.ignore(255, '\n');
    Item data = Item();
    auto* curr = &data;

    stack<decltype(curr)> st;
    st.push(curr);

    for (int i = 0; i < inputs; i++) {
        if (cin.peek() != '<') {
            cout << "Invalid input." << endl;
            return -1;
        }
        cin.ignore(1, '<');
        string tag;
        // cout << "st top: " << st.top().tag << endl;
        if (cin.peek() == '/') {
            cin.ignore(255, '/');
            getline(cin, tag, '>');
            // cout << "tag: " << tag << " stack top tag: " << st.top()->tag << endl;
            if (st.top()->tag != tag) {
                cout << "Invalid closing tag." << endl;
                return -1;
            } else {
                st.pop();
                curr = st.top();
            }
            cin.ignore(255, '\n');
        } else {
            string line;
            getline(cin, line);
            for (int i = 0; i < line.size(); i++) {
                // cout << "tag: " << tag << endl;
                char c = line[i];
                if (c == '>' || c == ' ') {
                    auto foo = new Item(tag);
                    // cout << "inserting tag: " << tag << " into: " << curr->tag << endl;
                    curr->mp.insert(pair<string, Item*> (tag, foo));
                    st.push(foo);
                    curr = foo;
                    if (c == ' ') {
                        istringstream lineIn(line.substr(i + 1));
                        getInput(lineIn, curr);
                    }
                    break;
                } else {
                    tag += c;
                }
            }
        }
    }

    //Query
    for (int i = 0; i < queries; i++) {
        string line;
        getline(cin, line);
        auto* curr = &data;
        string tag;
        // cout << "check for c (query): " << data.mp["a"]->mp.count('c') << endl;

        for (int i = 0; i < line.size(); i++) {
            char c = line[i];
            if (c == '.' || c == '~') {
                if (curr->mp.count(tag) == 0) {
                    // cout << "map Not Found!" << endl;
                    cout << "Not Found!" << endl;
                    break;
                }
                curr = curr->mp[tag];
                if (c == '.') {
                    tag.clear();
                    continue;
                } else {
                    if (i == line.size() - 1) {
                        cout << "Invalid query." << endl;
                        return -1;
                    }
                    tag = line.substr(i + 1);
                    if (curr->items.count(tag) == 0) {
                        // cout << "item Not Found!" << endl;
                        cout << "Not Found!" << endl;
                        break;
                    }
                    cout << curr->items[tag] << endl;
                }
            } else {
                tag += c;
            }
        }
    }
    return 0;
}
