#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& a, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(a[mid]);

    root->left = buildTree(a, start, mid - 1);
    root->right = buildTree(a, mid + 1, end);

    return root;
}

int sumTree(TreeNode* root) {
    if (root == NULL) return 0;

    int sum = root->val + sumTree(root->left) + sumTree(root->right);
    return sum;
}

int main() {
    int n, S;
    cin >> n >> S;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (a.size() > 1) {
        vector<int> b;
        for (int i = 0; i < a.size() - 1; i += 2) {
            b.push_back(a[i] + a[i + 1]);
        }
        if (a.size() % 2 == 1) {
            b.push_back(a[a.size() - 1]);
        }
        a = b;
    }

    TreeNode* root = buildTree(a, 0, a.size() - 1);
    int sum = sumTree(root) - S;

    cout << sum << endl;

    return 0;
}