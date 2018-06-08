#ifndef InverIndex_h
#define InverIndex_h
#include <string>
#include "Index.h"
template <class T>
class InverIndex
{
private:
	Index<T> *root;
    vector<T> full;
public:
    InverIndex()
	{
		root=0;
	};
    InverIndex(T t)
	{
		root = new Index<T>;
		root->key = t;
		root->thuoc = 0;
		root->next = 0;
	};

	void Add(T s, T Name)
	{
        full.push_back(Name);
        string h;
        for( int i=0; i<s.length(); i++ )
        {
            if( s[i] == 32 )
            {
                addWord( h , Name );
                h.clear();
                continue;
            }
            h.append( 1, s[i] );
        }
        if( h.length() )
                addWord( h , Name );
    };


	void addWord(T t, T Name)
	{
		Index<T> *p = new Index<T>;
		p->key = t;
		p->next = 0;
		p->thuoc.push_back(Name);

		if (root == 0) root = p;
		else
		{
            Index<T> *q = root;
            while (q->next != 0)
            {
                if (q->key==t)
                {
                    q->thuoc.push_back(Name);
                    return;
                }
                q=q->next;
            }
            q->next = p;
		}
	};



	void FindAnd(T s)
    {
        vector <T> kq;
        bool kt,ktt;
        kq=full;
        string h;
        for( int i=0; i<s.length(); i++ )
        {
            ktt=false;
            if( s[i] == 32 )
            {
                Index<T> *q = root;
                while ( q!=0 )
                {
                    if (q->key == h)
                    {
                        ktt=true;
                        for (int k=0; k < kq.size(); k++)
                        {
                            kt=false;
                            for (int j=0; j < q->thuoc.size(); j++)
                            if (kq[k]==q->thuoc[j]) kt=true;
                            if (kt==false) kq.erase(kq.begin()+k);
                        }
                        break;
                    }
                    q=q->next;
                }
                if (ktt==false)
                    {
                        cout << "khong tim thay cum tu nay" << endl;
                        system("pause");
                        return;
                    }
                h.clear();
                continue;
            }
            h.append( 1, s[i] );
        }
        ktt=false;
        if( h.length() )
        {
            Index<T> *q = root;
                while ( q!=0 )
                {
                    if (q->key == h) // tim thay tu nay trong cau truc Index.
                    {
                        ktt=true;
                        for (int i=0; i < kq.size(); i++)
                        {
                            kt=false;
                            for (int j=0; j < q->thuoc.size(); j++)
                            if (kq[i]==q->thuoc[j]) kt=true;
                            if (kt==false) kq.erase(kq.begin()+i);
                        }
                        break;
                    }
                    q=q->next;
                }
        if (ktt==false)
        {
            cout << "khong tim thay cum tu nay" << endl;
            system("pause");
            return;
        }
        }
        for (int i=0; i< kq.size(); i++) cout << kq[i] <<" ";
        cout << endl;
        system("pause");
    }

    void FindOr(T s)
    {
        vector<T> kq;
        kq.clear();
        string h="";
       // DisplayAll();
        bool kt;
        for( int i=0; i<s.length(); i++ )
        {
            if( s[i] == 32 )
            {
                Index<T> *p = root;
                while ( p!=0 )
                {
                    if ( p->key==h )
                    for (int k=0; k<p->thuoc.size(); k++)
                    {
                        kt=false;
                        for (int j=0; j<kq.size();j++)
                        if (p->thuoc[k]==kq[j]) kt=true;
                        if (kt==false) kq.push_back(p->thuoc[k]);
                    }
                    p=p->next;
                }
                h.clear();
                continue;
            }
            h.append( 1, s[i] );
        }
        if( h.length() )
        {
            Index<T> *q= root;
            while (q!=0)
            {
                if ( q->key==h )
                for (int i=0; i<q->thuoc.size(); i++)
                {
                    kt=false;
                    for (int j=0; j<kq.size();j++)
                    if (q->thuoc[i]==kq[j]) kt=true;
                    if (kt==false) kq.push_back(q->thuoc[i]);
                }
            q=q->next;
            }
        }
        if (kq.size()==0) cout <<"Khong tim thay cac tu nay" << endl;
        else for (int i=0; i<kq.size(); i++) cout <<kq[i]<<" ";
        system("pause");
    }

    void DisplayAll() const
	{
		Index<T> * p = root;
		while (p != 0)
		{
			cout << p->key << "; ";
			p = p->next;
		}
		system("pause");
	};
};

#endif
