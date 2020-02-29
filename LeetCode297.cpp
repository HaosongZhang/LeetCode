/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode *root)
	{
		if (!root)
		{
			return "[]";
		}
		queue<TreeNode *> q;
		q.push(root);
		stringstream ss;
		while (!q.empty())
		{
			root = q.front();
			q.pop();
			if (root)
			{
				q.push(root->left);
				q.push(root->right);
				ss << to_string(root->val) << ",";
			}
			else
			{
				ss << "null,";
			}
		}

		string data = ss.str();
		data = trimRightNulls(data, "null,");		// 去掉最后一层之后多余的 null
		data = data.substr(0, data.size() - 1); // 去掉最后一个 ,

		return "[" + data + "]";
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string input)
	{
		input = input.substr(1, input.length() - 2);
		if (!input.size())
		{
			return nullptr;
		}

		string item;
		stringstream ss;
		ss.str(input);

		getline(ss, item, ',');
		TreeNode *root = new TreeNode(stoi(item));
		queue<TreeNode *> nodeQueue;
		nodeQueue.push(root);

		while (true)
		{
			TreeNode *node = nodeQueue.front();
			nodeQueue.pop();

			if (!getline(ss, item, ','))
			{
				break;
			}

			if (item != "null")
			{
				int leftNumber = stoi(item);
				node->left = new TreeNode(leftNumber);
				nodeQueue.push(node->left);
			}

			if (!getline(ss, item, ','))
			{
				break;
			}

			if (item != "null")
			{
				int rightNumber = stoi(item);
				node->right = new TreeNode(rightNumber);
				nodeQueue.push(node->right);
			}
		}
		return root;
	}

	string trimRightNulls(string data, string target)
	{
		int size = target.size();
		while (data.size() > size && data.substr(data.size() - size, size) == target)
		{
			data = data.substr(0, data.size() - size);
		}
		return data;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
