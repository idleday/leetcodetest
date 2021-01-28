#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <cmath>
#include <cassert>
#include <algorithm>

#include "utils.hh"
#include "algo.hh"
#include "leetcode.hh"

using namespace std;

class median_of_two_sorted_arrayus {
    // https://leetcode-cn.com/problems/median-of-two-sorted-arrayus/

    double get_vector_middle(vector<int> &nums) {
        int i = (nums.size()-1) / 2;
        int j = (nums.size()) / 2;
        double f = ((double)nums.at(i) + nums.at(j))/2;
    //    cout << "middle " << f << endl;
        return f;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        insert_sort(nums1, nums2);
        return get_vector_middle(nums1);
    }

};

class regular_expression_matching{
    // https://leetcode-cn.com/problems/regular-expression-matching/
	bool isMatch(string s, string p) {
		cout << s << "(" << s.length() << ") vs " << p << "(" << p.length() << ")" << endl ;
		if (p.length() == 0)
			return s.length() == 0;
		if (p.length() == 1)
			return s.length() == 1 && (p[0] == s[0] || p[0] == '.');

		int i=0, j=0;
		// ! x*
		while (i<s.length() && j<p.length()-1 && p[j+1] != '*') {
			if (p[j] == '.' || p[j] == s[i]) {
				i++;
				j++;
			}
			else {
				return false;
			}
		}
		if (j == p.length() - 1) {// x$
			return (i == s.length() - 1 && (p[j] == s[i] || p[j] == '.'));
		}
		else if (p[j+1] != '*') {
			return false;
		}
		else if (p[j] != '.') { // a*
			string p1 = p.substr(j+2);
			int k = i;
			while (s[k] == p[j] && k<=s.length()) {
				if (isMatch(s.substr(k), p1))
					return true;
				k++;
			}
			return isMatch(s.substr(k), p1);
		}
		else { // .*
			string p1 = p.substr(j+2);
			int k = i;
			while (k<=s.length()) {
				if (isMatch(s.substr(k), p1))
					return true;
				k++;
			}
		}
		return false;
	}

public:
    void test() {
		assert(isMatch("aa", "a") == false);
		assert(isMatch("aa", "a*") == true);
		assert(isMatch("ab", ".*") == true);
		assert(isMatch("aab", "c*a*b") == true);
		assert(isMatch("mississippi", "mis*is*ip*.") == true);
		assert(isMatch("mississippi", "mis*is*p*.") == false);
		assert(isMatch("aaa", "ab*a*c*a") == true);
		assert(isMatch("ab", ".*..") == true);
		assert(isMatch("a", "b..") == false);
		assert(isMatch("", "c*c*") == true);
		assert(isMatch("a", ".*..a*") == false);
		cout << "completed" << endl;
	}

};

class longest_palindromic_substring {
    // https://leetcode-cn.com/problems/longest-palindromic-substring/
	string longestPalindrome(string s) {
		size_t len = s.length();
		size_t maxcnt = 0, maxstart = 0, curcnt1=0, curcnt2=0, curstart = 0;
		for (int i=0; i<len; i++) {
			int j = 1;
			curcnt1 = 0;
			curcnt2 = 0;
			while ( i-j >= 0 && i+j <len) {
				if (s[i-j] != s[i+j])
					break;
				j++;
			}
			curcnt1 = j * 2 - 1;
			if (curcnt1 > maxcnt) {
				maxcnt = curcnt1;
				maxstart = i-j+1;
			}
			if (s[i] == s[i+1]) {
				j = 1;
				while ( i-j >= 0 && i+1+j < len) {
					if (s[i-j] != s[i+1+j])
						break;
					j++;
				}
				curcnt2 = j * 2;
				if (curcnt2> maxcnt) {
					maxcnt = curcnt2;
					maxstart = i-j+1;
				}
			}
		}
		return s.substr(maxstart, maxcnt);
	}

};

class convert_to_z{
    // ???
	string convert2shapeZ(string s, int numRows) {
		if (numRows < 2)
			return s;
		int i = 0, j = 0;
		int groupSz = numRows * 2 - 2;
		int groupNum = (s.length() + groupSz - 1) / groupSz;
		int numCols = groupNum* (numRows-1);
		char result[numRows * numCols];
		for (i=0; i<numRows*numCols; i++) result[i] = 0;
		for (i=0; i<s.length(); i++) {
			int group = i/groupSz;
			int offsetInGrp = i%groupSz;
			int row,col;
			if (offsetInGrp < numRows) {
				row = offsetInGrp;
				col = group * (numRows - 1);
			}
			else {
				row = numRows * 2 - offsetInGrp - 2;
				col = group * (numRows - 1) + offsetInGrp - numRows + 1;
			}
	//		cout << s[i] << " row " << row << " col " << col << endl;
			int index = (numCols) * (row) + col;
			result[index] = s[i];
		}
		char resultStr[s.length()];
		int res_i = 0;
		for (i=0; i<numRows; i++) {
			for (j=0; j<numCols; j++) {
				int index = (numCols) * (i) + j;
				if (result[index] != 0) {
	//				cout << result[index];
					s[res_i++] = result[index];
				}
				else {
	//				cout << " ";
				}
			}
	//		cout << endl;
		}
		return s;
	}

};

class maximum_depth_of_binary_tree {
    // https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int len1 = maxDepth(root->left);
        int len2 = maxDepth(root->right);
        return len1 > len2 ? len1 + 1 : len2 + 1;
    }

    int maxDepthz(TreeNode* root) {
        if (root == NULL)
            return 0;
        std::stack<TreeNode*> st;
        int max_len = 0;
        TreeNode *n = root;
        TreeNode *pn;
        do {
            if (n == NULL) {
                if (st.size() == 0)
                    return max_len;
                pn = st.top();
                while (pn->right == n)
                {
                    n = pn;
                    st.pop();
                    //std::cout << "pop " << n->val << std::endl;
                    if (st.size() == 0)
                        return max_len;
                    pn = st.top();
                }
                n = pn->right;
            }
            else {
                st.push(n);
                //std::cout << "push " << n->val << std::endl;
                max_len = max_len < st.size() ? st.size() : max_len;
                //std::cout << "max_len " << max_len << std::endl;
                n = n->left;
            }
        } while (n != root);
        return max_len;
    }

};

class container_with_most_water {
    // https://leetcode-cn.com/problems/container-with-most-water/
    int maxArea(vector<int>& height) {
        vector<int>::iterator l=height.begin(), r=height.end()-1;
        int64_t max_area = 0;
        while (l < r) {
            max_area = max(max_area, (r-l)*min(*l,*r));
            if(*l < *r)
                l++;
            else
                r--;
        }
        return max_area;
	}

public:
    void test() {
        vector<int> v;
        v = string2vector("[1,8,6,2,5,4,8,3,7]");
        cout << maxArea(v) << endl;
        v = string2vector("[1,1]");
        cout << maxArea(v) << endl;
    }

};

class three_sum_0 {
    // https://leetcode-cn.com/problems/3sum/
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i=0; i<sz; i++) {
            if (i>0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int j=i+1, k=sz-1;
            while (j<sz && j < k) {
                if (nums[j] + target < 0) break;
                if (j-1!=i && nums[j] == nums[j-1]) {
                    j++;
                    continue;
                }
                while (k>j) {
                    if (nums[j] + nums[k] > target)
                        k--;
                    else if (nums[j] + nums[k] == target){
                        res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                        break;
                    }
                    else
                        break;
                }
                j++;
            }
        }
        return res;
    }

public:
    void test() {
        vector<int> v = string2vector("[-1,0,1,2,-1,-4]");
        vector< vector<int> > res = threeSum(v);
        for (int i=0; i<res.size(); i++)
            vector_dump(res[i]);

    }
};

class letter_combinations_of_a_phone_number {
    // https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) {
            return res;
        }
        static string a[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> wordlist = letterCombinations(digits.substr(1));
        string bytelist = a[digits[0] - '2'];
//        cout << bytelist << " w " << wordlist.size() << endl;
        for (int i=0; i<bytelist.length(); i++)
        {
            string c = bytelist.substr(i,1);
            if (wordlist.size() > 0)
            {
                for (int j=0; j<wordlist.size(); j++)
                {
                    string newword = c;
                    newword.append(wordlist[j]);
                    res.push_back(newword);
                }
            }
            else {
                res.push_back(c);
            }
        }
//        cout << res.size() << endl;
        return res;
    }

public:
    void test() {
        vector<string> v = letterCombinations("2345");
        cout << v.size() << endl;
        vector_dump(v);
    }

};

class remove_nth_node_from_end_of_list {
    // https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
       ListNode *node1=&dummy;
       ListNode *node2=&dummy;
       int i=0;
       while(node2->next != nullptr) {
           if (i>=n)
               node1 = node1->next;
           node2 = node2->next;
           i++;
       }
       node1->next = node1->next->next;
       if (node1 == &dummy)
           return node1->next;
       return head;
    }
};

class valid_parentheses {
    // https://leetcode-cn.com/problems/valid-parentheses/
public:
    bool isValid(string s) {
        map<char,char> m = {{'(',')'},{'[',']'},{'{','}'}};
        stack<char> st;
        for (char c: s)
        {
            if (st.empty() || m[st.top()] != c)
                st.push(c);
            else
                st.pop();
        }
        return st.empty();
    }
};

class merge_two_sorted_lists {
    // https://leetcode-cn.com/problems/merge-two-sorted-lists/
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l2 == nullptr) return l1;
        if (l1 == nullptr) return l2;
        ListNode *h1 = new ListNode(0, l1);
        ListNode *tmp;
        ListNode *p1 = h1;
        ListNode *n1=l1, *n2=l2;
        while (n1 && n2) {
            while (n2 && n2->val < n1->val) {
                p1->next = n2;
                tmp = n2->next;
                p1 = n2;
                n2->next = n1;
                n2 = tmp;
            }
            if (!n2)
                return h1->next;
            while (n1 && n1->val <= n2->val) {
                p1 = n1;
                n1 = n1->next;
            }
        }
        if (!n1)
            p1->next = n2;
        
        return h1->next;
    }

    void dump(ListNode *l) {
        while (l) {
            cout << l->val << " ";
            if (l == l->next) {
                cout << "loop!";
                return;
            }
            l = l->next;
        }
        cout << endl;
    }

    void test() {
        ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        dump(mergeTwoLists(l1, l2));
    }
};

void hot100::test() {
    merge_two_sorted_lists().test();
}
