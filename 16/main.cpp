#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    int len_s = s.length(), len_p = p.length();
    vector<int> result;

    if (len_s < len_p) return result;

    // Счетчики для символов
    unordered_map<char, int> p_count, s_count;

    // Инициализация счетчиков
    for (char c : p) {
        p_count[c]++;
    }

    for (int i = 0; i < len_p; i++) {
        s_count[s[i]]++;
    }

    // Сравнение счетчиков
    if (s_count == p_count) {
        result.push_back(0);
    }

    // Скользящее окно
    for (int i = len_p; i < len_s; i++) {
        // Удаляем старый символ
        s_count[s[i - len_p]]--;
        if (s_count[s[i - len_p]] == 0) {
            s_count.erase(s[i - len_p]);
        }
        // Добавляем новый символ
        s_count[s[i]]++;

        // Сравнение счетчиков
        if (s_count == p_count) {
            result.push_back(i - len_p + 1);
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> anagram_indices = findAnagrams(s, p);

    // Вывод результата
    for (int index : anagram_indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
