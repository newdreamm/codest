#pragma once


#include <iostream>
#include <assert.h>

using namespace std;

namespace myl
{
	// List�Ľڵ���
	template<class T>
	struct ListNode
	{
		ListNode(const T& val = T())
			: _prev(nullptr)
			, _next(nullptr)
			, _val(val)
		{}

		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _val;
	};


	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;

		// Ref �� Ptr ������Ҫ�ض����£�ʵ�ַ��������ʱ��Ҫ�õ�
	public:
		typedef Ref Ref;
		typedef Ptr Ptr;
	public:
	
		// ����
		ListIterator(Node* node = nullptr)
			: _node(node)
		{}


		// ����ָ��������Ϊ
		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

	
		// ������֧���ƶ�
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_node = _node->_next;
			return temp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_node = _node->_prev;
			return temp;
		}

	
		// ������֧�ֱȽ�
		bool operator!=(const Self& l)const
		{
			return _node != l._node;
		}

		bool operator==(const Self& l)const
		{
			return _node != l._node;
		}

		Node* _node;
	};

	template<class Iterator>
	class ReverseListIterator
	{
		// typename����������ȷ���߱�������Ref��Iterator���е�һ�����ͣ������Ǿ�̬��Ա����
		// ��Ϊ��̬��Ա����Ҳ�ǰ��� ����::��̬��Ա������ �ķ�ʽ���ʵ�
	public:
		typedef typename Iterator::Ref Ref;
		typedef typename Iterator::Ptr Ptr;
		typedef ReverseListIterator<Iterator> Self;
	public:

		// ����
		ReverseListIterator(Iterator it)
			: _it(it)
		{}


		// ����ָ��������Ϊ
		Ref operator*()
		{
			Iterator temp(_it);
			--temp;
			return *temp;
		}

		Ptr operator->()
		{
			return &(operator*());
		}


		// ������֧���ƶ�
		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			--_it;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			++_it;
			return temp;
		}

	
		// ������֧�ֱȽ�
		bool operator!=(const Self& l)const
		{
			return _it != l._it;
		}

		bool operator==(const Self& l)const
		{
			return _it != l._it;
		}

		Iterator _it;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;

	public:
		// ���������
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T&> const_iterator;

		// ���������
		typedef ReverseListIterator<iterator> reverse_iterator;
		typedef ReverseListIterator<const_iterator> const_reverse_iterator;
	public:

		// List�Ĺ���
		list()
		{
			CreateHead();
		}

		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}

		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& l)
		{
			CreateHead();

			// ��l�е�Ԫ�ع�����ʱ��temp,Ȼ���뵱ǰ���󽻻�
			list<T> temp(l.begin(), l.end());
			this->swap(temp);
		}

		list<T>& operator=(list<T> l)
		{
			this->swap(l);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

	
		// List�ĵ�����
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(begin());
		}


		// List���������
		size_t size()const
		{
			Node* cur = _head->_next;
			size_t count = 0;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}

			return count;
		}

		bool empty()const
		{
			return _head->_next == _head;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				// ��ЧԪ�ظ������ٵ�newsize
				while (newsize < oldsize)
				{
					pop_back();
					oldsize--;
				}
			}
			else
			{
				while (oldsize < newsize)
				{
					push_back(data);
					oldsize++;
				}
			}
		}
	
		// List��Ԫ�ط��ʲ���
		T& front()
		{
			return _head->_next->_val;
		}

		const T& front()const
		{
			return _head->_next->_val;
		}

		T& back()
		{
			return _head->_prev->_val;
		}

		const T& back()const
		{
			return _head->_prev->_val;
		}


		// List�Ĳ����ɾ��
		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			erase(begin());
		}

		// ��posλ��ǰ����ֵΪval�Ľڵ�
		iterator insert(iterator pos, const T& val)
		{
			Node* pNewNode = new Node(val);
			Node* pCur = pos._node;
			// �Ƚ��½ڵ����
			pNewNode->_prev = pCur->_prev;
			pNewNode->_next = pCur;
			pNewNode->_prev->_next = pNewNode;
			pCur->_prev = pNewNode;
			return iterator(pNewNode);
		}

		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos)
		{
			// �ҵ���ɾ���Ľڵ�
			Node* pDel = pos._node;
			Node* pRet = pDel->_next;

			// ���ýڵ�������в�������ɾ��
			pDel->_prev->_next = pDel->_next;
			pDel->_next->_prev = pDel->_prev;
			delete pDel;

			return iterator(pRet);
		}

		void clear()
		{
			Node* cur = _head->_next;

			// ����ͷɾ��ɾ��
			while (cur != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}

			_head->_next = _head->_prev = _head;
		}

		void swap(myl::list<T>& l)
		{
			std::swap(_head, l._head);
		}

	private:
		void CreateHead()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}
	private:
		Node* _head;
	};
}



// ��ģ��ʵ�ֵ�list���в���
// �����ӡ����
template<class T>
void PrintList(const myl::list<T>& l)
{
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;
}

// ����List�Ĺ���
void TestBiteList1()
{
	myl::list<int> l1;
	myl::list<int> l2(10, 5);
	PrintList(l2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	myl::list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l3);

	myl::list<int> l4(l3);
	PrintList(l4);

	l1 = l4;
	PrintList(l1);
}

// PushBack()/PopBack()/PushFront()/PopFront()
void TestBiteList2()
{
	// ����PushBack��PopBack
	myl::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	PrintList(l);

	l.pop_back();
	l.pop_back();
	PrintList(l);

	l.pop_back();
	cout << l.size() << endl;

	// ����PushFront��PopFront
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	PrintList(l);

	l.pop_front();
	l.pop_front();
	PrintList(l);

	l.pop_front();
	cout << l.size() << endl;
}

// ����insert��erase
void TestBiteList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	myl::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto pos = l.begin();
	l.insert(l.begin(), 0);
	PrintList(l);

	++pos;
	l.insert(pos, 2);
	PrintList(l);

	l.erase(l.begin());
	l.erase(pos);
	PrintList(l);

	// posָ��Ľڵ��Ѿ���ɾ����pos������ʧЧ
	cout << *pos << endl;

	auto it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	cout << l.size() << endl;
}

// ���Է��������
void TestBiteList4()
{
	int array[] = { 1, 2, 3, 4, 5 };
	myl::list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	const myl::list<int> cl(l);
	auto crit = l.rbegin();
	while (crit != l.rend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}