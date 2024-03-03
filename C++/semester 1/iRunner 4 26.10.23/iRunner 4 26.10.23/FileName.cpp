//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int p, n;
//    cin >> n;
//    cin >> p;
//    if (p % (n - 1) == 0)
//        cout << (p / (n - 1)) - 1 + p << " " << (p / (n - 1)) + p;
//    else
//        cout << (p / (n - 1)) + p << " " << (p / (n - 1)) + p;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    long N, M, sum = 0;
//    cin >> N;
// 
//    for (int i = 0; i < N; i++)
//    {
//        cin >> M;
//        sum += M;
//    }
//
//    cout << sum - N + 1;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    const int N = 100;
//    int n, cards[N];
//    cin >> n;
//    for (int i = 0; i < n; i++)
//         cin >> cards[i];
//        
//    int max = cards[0], min = cards[0];
//    for (int i = 1; i < n; i++)
//    {
//        if (cards[i] > max)
//            max = cards[i];
//        if (cards[i] < min)
//            min = cards[i];
//    }
//
//    cout << max - min;    
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    long long N;
//    int sum = 0, A, cnt = 0;
//    cin >> N;
//    
//    for (int i = 0; i < N; i++)
//    {
//        cin >> A;
//
//        if (A == 0)
//            cnt++;
//        if(cnt == 1 && A != 0)
//            sum++;
//    }
//    if (cnt == 0)
//        cout << -1;
//    else if (cnt == 1)
//        cout << -2;
//    else
//        cout << sum;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int a, b, c;
//    cin >> a >> b >> c;
//    //2(m+n) = a
//    //2(m + k) = b
//    //2(n + p) = c
//    //2(k + p) = ?
//
//    //m = a/2 - n
//    //k = b/2 - a/2 + n
//    //p = c/2 - n
//    //k + p = b/2 - a/2 + n + c/2 - n = b/2 - a/2 + c/2
//    //2(k + p) = b - a + c
//    cout << (double)(b - a + c);
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int N, S1, S2, S3, S4, sum;
//    cin >> N;
//    cin >> S1 >> S2 >> S3 >> S4;
//
//    sum = N * 4 - (S1 + S2 + S3 + S4);
//
//    if (sum < N)
//        cout << N - sum;
//    else
//        cout << 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    long long x, y, z, k;
//    cin >> x >> y >> z >> k;
//
//    if (k % 2 == 0)
//        cout << x - y;
//    else
//        cout << y - x;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    long double a, b, c, d, n1, n2;
//    cin >> a >> b;
//    cin >> c >> d;
//    n1 = a / b;
//    n2 = c / d;
//    if (n1 < n2)
//        cout << -1;
//    else if (n1 == n2)
//        cout << 0;
//    else
//        cout << 1;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int n, count = 0;
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        long int a;
//        cin >> a;
//        bool flag = false;
//        int pos = 1;
//        while (a > 0) {
//            if ((a % 10) % 2 == pos % 2)
//                flag = true;
//            else {
//                flag = false;
//                break;
//            }
//            pos++;
//            a /= 10;
//        }
//        if (flag)
//            count++;
//    }
//    cout << count;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	long long sum;
//	int n;
//	string answer;
//	cin >> sum >> n;
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 9; j >= 0; j--) {
//			if (j <= sum) {
//				answer += to_string(j);
//				sum -= j;
//				break;
//			}
//		}
//	}
//	if (sum != 0)
//		cout << -1;
//	else
//		cout << answer;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	long long n, a, count = 0, first;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		if (i == 0)
//			first = a;
//		else
//			if (a == first)
//				count++;
//	}
//	cout << count;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n, post, count = 0, length = 1, maxLen = 1, minLen = 100000;
//	long a;
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		if (i > 0) {
//			if (a == post) {
//				length++;
//			}
//			else if (a != post && length > 1) {
//				if (length > maxLen)
//					maxLen = length;
//
//				if (length < minLen)
//					minLen = length;
//				
//				count++;
//				length = 1;
//			}
//		}
//		post = a;
//		if (i == n - 1) {
//			if (length > 1) {
//				if (length > maxLen)
//					maxLen = length;
//
//				if (length < minLen)
//					minLen = length;
//
//				count++;
//			}
//		}
//	}
//	if (count == 0) {
//		maxLen = 0;
//		minLen = 0;
//	}
//	cout << count << " " << maxLen << " " << minLen;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int m, n, k, team = 0;
//	cin >> m >> n >> k;
//	while (m >= 2 && n >= 1 && k >= 3) {
//		m -= 2;
//		n -= 1;
//		k -= 3;
//		team++;
//	}
//	cout << team;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	long long sumOdd = 0, sumEven = 0;
//	bool div4 = false, div9 = false, div11 = false;
//	string M;
//	getline(cin, M);
//	if (M.size() == 1) {
//		if (M == "0") {
//			div4 = true;
//			div9 = true;
//			div11 = true;
//		}
//		else if (M == "4" || M == "8")
//			div4 = true;
//		else if (M == "9")
//			div9 = true;
//
//	}
//	else
//	{
//		for (long long i = 0; i < M.size(); i += 2) {
//			sumOdd += M[i] - '0';
//		}
//		for (long long j = 1; j < M.size();  j += 2) {
//			sumEven += M[j] - '0';
//		}
//
//		if (stoi(M.substr(M.size() - 2, 2)) % 4 == 0)
//			div4 = true;
//
//		if ((sumOdd + sumEven) % 9 == 0)
//			div9 = true;
//		if ((sumOdd - sumEven) % 11 == 0)
//			div11 = true;
//	}
//
//	if (!div4 && !div9 && !div11)
//		cout << 1;
//	else if (div4 && !div9 && !div11)
//		cout << 2;
//	else if (!div4 && div9 && !div11)
//		cout << 3;
//	else if (!div4 && !div9 && div11)
//		cout << 4;
//	else if (div4 && div9 && !div11)
//		cout << 5;
//	else if (div4 && !div9 && div11)
//		cout << 6;
//	else if (!div4 && div9 && div11)
//		cout << 7;
//	else if (div4 && div9 && div11)
//		cout << 8;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    long long n;
//    cin >> n;
//    long long max, a, sum = 0, maxSum = 0, j = n - 1;
//    bool find = false;
//    vector<long long> array;
//    for (long long i = 0; i < n; i++) {
//        cin >> a;
//        array.push_back(a);
//    }
//    cin >> max;
//
//    sort(begin(array), end(array));
//
//    for (long long c = 0; (c < j) && !find; c++) {
//        long long i = c + 1;
//        while (i < j && !find) {
//            sum = array[c] + array[i] + array[j];
//            if (sum > max) {
//                j--;
//            }
//            else if (sum == max) {
//                maxSum = sum;
//                find = true;
//            }
//            else {
//                if (sum > maxSum) {
//                    maxSum = sum;
//                }
//                i++;
//            }
//        }
//    }
//
//    cout << maxSum;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string nums, numsCompressed;
//    int count = 1;
//    cin >> nums;
//
//    for (long long i = 0; i < nums.size(); i++) {
//        if (nums[i] == nums[i + 1]) {
//            count++;
//        }
//        else {
//            if (count >= 4) {
//                numsCompressed += "(" + to_string(count) + ")" + nums[i];
//            }
//            else {
//                numsCompressed += string(count, nums[i]);
//            }
//            count = 1;
//        }
//    }
//
//    cout << numsCompressed;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string nums, numsUnc = "";
//    int count = 0;
//    cin >> nums;
//
//    for (long long i = 0; i < nums.size(); i++) {
//        if (nums[i] != '(') {
//            numsUnc += nums[i];
//        }
//        else {
//            string countString = nums.substr(i + 1, nums.find(")") - i - 1);
//            count = stoi(countString);
//            numsUnc += string(count, nums[nums.find(")") + 1]);
//            nums.erase(nums.find(")"), 1);
//            i += 1 + countString.size();
//        }
//    }
//
//    cout << numsUnc;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    vector<int> count = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
//    vector<unsigned long long> value = { 1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230, 200560490130, 7420738134810, 304250263527210, 13082761331670030, 614889782588491410 };
//    
//    long long num;
//    int prime1, prime2;
//    cin >> num;
//    
//    for (int i = 0; i < 16; i++) {
//        for (int j = i; j < 16; j++) {
//            if (value[j] - value[i] == num) {
//                prime1 = count[j];
//                prime2 = count[i];
//            }
//        }
//    }
//
//    cout << prime1 << ' ' << prime2;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    long long N, array[3], a, b, c, max, indMax = 0, type1 = 0, type2 = 0, type3 = 0, type4 = 0, type5 = 0;
//    cin >> N;
//    
//    for (long long i = 0; i < N; i++) {
//        max = 0;
//        for (int x = 0; x < 3; x++) {
//            cin >> array[x];
//            if (array[x] > max) {
//                max = array[x];
//                indMax = x;
//            }
//        }
//
//        long tmp = array[indMax];
//        array[indMax] = array[2];
//        array[2] = tmp;
//        
//        a = array[0];
//        b = array[1];
//        c = array[2];
//
//        if (a + b < c) { type1++; }
//        else if (a + b == c) { type2++; }
//        else if (a * a + b * b > c * c) { type3++; }
//        else if (a * a + b * b == c * c) { type4++; }
//        else if (a * a + b * b < c * c) { type5++; }
//    }
//
//    cout << type1 << ' ' << type2 << ' ' << type3 << ' ' << type4 << ' ' << type5;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int N, T, k, count = 0, a;
//    bool include = false;
//    cin >> N >> T >> k;
//    vector<int> ingtidients (k);
//    for (int i = 0; i < k; i++) {
//        cin >> ingtidients[i];
//    }
//
//    for (int i = 0; i < N; i++) {
//        cin >> k;
//        include = false;
//        for (int i = 0; i < k; i++) {
//            cin >> a;
//            if (find(ingtidients.begin(), ingtidients.end(), a) != ingtidients.end()) {
//                include = true;
//            }
//        }
//        if (!include) { count++; }
//    }
//    cout << count;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
////int power2mod11(int n) {
////	int result = 1; 
////	for (long long i = 0; i < n; i++) {
////		result = (result * 2) % 11; 
////	}
////	return result; }
////
////int main() {
////	int n; 
////	cin >> n;
////	
////	cout << power2mod11(n);
////}
//
//int main() {
//	string n;
//	cin >> n;
//
//	if (n[n.size() - 1] == '0') {
//		cout << 1;
//	}
//	else if (n[n.size() - 1] == '1') {
//		cout << 2;
//	}
//	else if (n[n.size() - 1] == '2') {
//		cout << 4;
//	}
//	else if (n[n.size() - 1] == '3') {
//		cout << 8;
//	}
//	else if (n[n.size() - 1] == '4') {
//		cout << 5;
//	}
//	else if (n[n.size() - 1] == '5') {
//		cout << 10;
//	}
//	else if (n[n.size() - 1] == '6') {
//		cout << 9;
//	}
//	else if (n[n.size() - 1] == '7') {
//		cout << 7;
//	}
//	else if (n[n.size() - 1] == '8') {
//		cout << 3;
//	}
//	else if (n[n.size() - 1] == '9') {
//		cout << 6;
//	}
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	long count = 0, k, n, min = 4 * 10e9, minK = 4 * 10e9, a, pos = 0, x = 0;
//	cin >> n >> k;
//	vector<vector<long>> nums(2, vector<long>(n, -1));
//
//
//	for (long i = 0; i < n; i++) {
//		cin >> a;
//
//		if (a < min) {
//			min = a;
//		}
//
//		bool flag = false;
//		for (x = 0; x < pos; x++) {
//
//			if (nums[0][x] == a) {
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) {
//			nums[0][pos] = a;
//			nums[1][pos] = 1;
//			pos++;
//		}
//		else {
//			nums[1][x]++;
//
//			if (nums[1][x] == k) {
//				count++;
//
//				if (a < minK) {
//					minK = a;
//				}
//			}
//		}
//	}
//
//
//	cout << count << ' ';
//
//	if (count == 0) {
//		cout << min;
//	}
//	else {
//		cout << minK;
//	}
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//bool palindrome(string str) {
//	for (int i = 0; i < str.length() / 2; ++i)
//	{
//		if (str[i] != str[str.length() - i - 1])
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//int main() {
//	string word;
//	bool flag = true;
//	cin >> word;
//
//	for (int i = 0; i < word.length() && flag; i++) {
//		string newWord = word.substr(i) + word.substr(0, i);
//
//		if (palindrome(newWord)) {
//			cout << i + 1 << "\n";
//			flag = false;
//		}
//	}
//
//	if (flag)
//		cout << 0 << "\n";
//}

//#include <iostream>
//#include <map>
//using namespace std;
//
//int main()
//{
//    long N, K, num;
//    cin >> N >> K;
//    map<long, long> numbers;
//    for (long long i = 0; i < N; i++) {
//        cin >> num;
//        numbers[num]++;
//    }
//
//    long long count = 0, min = 10e12 + 1, minK = 10e12 + 1;
//
//    for (const auto& it : numbers) {
//        if (it.second == K) {
//            count++;
//
//            if (it.first < minK) {
//                minK = it.first;
//            }
//        }
//    }
//
//    for (const auto& it : numbers) {
//        if (it.first < min) {
//            min = it.first;
//        }
//    }
//
//    if (count == 0) {
//        cout << count << " " << min;
//    }
//    else {
//        cout << count << " " << min;
//    }
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int M, N;
//    long long K, Q, x, y;
//    cin >> M >> N >> K >> Q;
//    
//    vector<vector<int>> field (M, vector<int>(N, 0));
//
//    for (long long i = 0; i < K; i++) {
//        cin >> x >> y;
//        field[x - 1][y - 1] = 1;
//    }
//
//    int X[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//    int Y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//
//
//    for (int i = 0; i < Q; ++i) {
//        int x, y, count = 0;
//        cin >> x >> y;
//
//        if (field[x - 1][y - 1] == 1) {
//            cout << "*";
//            return 0;
//        }
//
//        for (int k = 0; k < 8; k++)
//        {
//            int newX = x + X[k];
//            int newY = y + Y[k];
//
//            if (newX > 0 && newX <= M && newY > 0 && newY <= N)
//            {
//                if (field[newX - 1][newY - 1] == 1)
//                {
//                    count++;
//                }
//            }
//        }
//
//        cout << count << endl;
//    }
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    int M, N, K, Q;
//    vector<int>  answers;
//    cin >> M >> N >> K >> Q;
//
//    vector<vector<int>> minefield(M, vector<int>(N, 0));
//
//
//    for (int i = 0; i < K; ++i) {
//        int x, y;
//        cin >> x >> y;
//        minefield[x - 1][y - 1] = 1;
//    }
//
//
//    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
//    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//
//
//    for (int i = 0; i < Q; ++i) {
//        int x, y;
//        cin >> x >> y;
//
//
//        if (minefield[x - 1][y - 1] == 1) {
//            for (int i : answers)
//                cout << i << '\n';
//            cout << "*\n";
//            return 0;
//        }
//
//
//        int mines_count = 0;
//        for (int dir = 0; dir < 8; ++dir) {
//            int nx = x + dx[dir];
//            int ny = y + dy[dir];
//
//
//            if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && minefield[nx - 1][ny - 1] == 1) {
//                mines_count++;
//            }
//        }
//
//        answers.push_back(mines_count);
//    }
//    for (int i : answers)
//        cout << i << '\n';
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//class segment {
//    int a, b;
//
//public:
//    segment(int a, int b) {
//        this->a = a;
//        this->b = b;
//    }
//
//    int getA() const {
//        return a;
//    }
//    int getB() const {
//        return b;
//    }
//
//    int length() const {
//        return b - a;
//    }
//};
//
//bool comparing(const segment& S1, const segment& S2) {
//    if (S1.length() == S2.length()) {
//        return S1.getA() < S2.getA();
//    }
//    else {
//        return S1.length() > S2.length();
//    }
//}
//
//int main() {
//    int N, a, b;
//    vector<segment> segments;
//
//    ifstream input("in.txt");
//    input >> N;
//
//    for (int i = 0; i < N; i++) {
//        input >> a >> b;
//
//        segments.push_back(segment(a, b));
//    }
//
//    sort(segments.begin(), segments.end(), comparing);
//
//    input.close();
//
//    ofstream output("out.txt");
//
//    for (int i = 0; i < N; i++) {
//        output << segments[i].getA() << ' ' << segments[i].getB() << endl;
//    }
//
//    output.close();
//}