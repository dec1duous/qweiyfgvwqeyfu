#ifndef NN_HPP
#define NN_HPP

#include <vector>

enum class Action {
	Mul = 0,
	Div = 1,
	Add = 2,
	Sub = 3
};

class Node
{
protected:
	std::vector<Node *> links;
	Action act;
	double data;

public:
	Node(Action act, double data = 1.0, double weight = 1.0):
		act(act), data(data), weight(weight)
	{}
	
	double weight;
	
	void link(Node *oth) {
		links.push_back(oth);
	}
	void unlink(Node *oth) {
		for (auto i = 0; i != links.size(); ++i) {
			if (links[i] == oth) {
				links.erase(links.begin() + i);
				return;
			}
		}
	}
	void reset(double data = 1.0) {
		this->data = data;
	}
	double value() {
		return data;
	}
	void signal() {
		if (act == Action::Mul)
		{
			for (auto node: links) {
				data *= node->data;
			}
		} else if (act == Action::Div)
		{
			for (auto node: links) {
				data /= node->data;
			}
		} else if (act == Action::Add)
		{
			for (auto node: links) {
				data += node->data;
			}
		} else if (act == Action::Sub)
		{
			for (auto node: links) {
				data -= node->data;
			}
		}
	}
}

// 

class BasicNetwork
{
public:
	std::vector<std::vector<Node>> layers;
	
	create(int inputNodes, int outputNodes) {
		
}

int main() {
	BasicNetwork nw;
	nw.layers[0].
	
#endif
