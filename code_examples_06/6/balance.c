#include "balance.h"

/*
http://kvodo.ru/avl-tree.html
http://www.cyberforum.ru/cpp-beginners/thread153292.html
*/

int min(int a, int b) {  if (a < b)  return a;  else  return b;  }
int max(int a, int b) {  if (a > b)  return a;  else  return b;  }

// функция определения высоты поддерева
int node_height(struct tree_node* node)  // снизу вверх
{
    int res = 0;

    while (node)
    {
        node = node->up;
        res++;
    }

    res--;

    return res;
}

int get_max(struct tree_node* node)
{
    int m   = 0;  if (node)  m = 1 + max(get_max(node->left), get_max(node->right)); return m;
}

int get_max_sublen(struct tree_node* node)
{
    int m = 0;  m = get_max(node);  m--;  return m;
}

int get_balance_factor(struct tree_node* node)  
{
	int lef = 0;  int rig = 0;       
    // --> по левому поддереву   // методом подминимумов и подмаксимумов  будет возникать проблема с балансировкой
    if (node)  {  lef = 1 + get_max_sublen(node->left);  rig = 1 + get_max_sublen(node->right);  }
	return lef - rig;  // или наоборот   ----////////////////////////////////////////////////////////////////////////////////////////////////
}

struct tree_node* turn_min_on(struct tree_node* r, struct tree_node* p) // p - parent
{
    struct tree_node* t = r->left;//Запоминаем адрес левого элемента
    r->left = t->right;//направляем левый указатель текущего элемента на правого потомка его левого потомка
    t->right = r;//Направляем правый указатель левого потомка на текущий элемент
    
    if(!p) {  r = t; return r;  }
    if(get_balance_factor(p) <= get_balance_factor(t))  p->right = t;  else p->left = t;  //напрявляем указатели предшествуюшего элемента на сбалансированую ветку. // <--- заменить как-нибудь вычислить показатель сбалансированности
    
	return r; // <-- может быть //
}

struct tree_node* turn_min_rev(struct tree_node* r, struct tree_node* p)//
{
    struct tree_node* t=r->right;
    r->right=t->left;
    t->left=r;
    
    if (p==NULL) {r = t; return r;  }
    if (get_balance_factor(p) <= get_balance_factor(t))  p->right = t;
    else p->left = t;
	return r;
}

struct tree_node* turn_big_on(struct tree_node* r, struct tree_node* p)
{
    struct tree_node* t=r->left->right;
    r->left->right=t->left;
    t->left=r->left;
    r->left=t->right;
    t->right=r;
 
    if (p==NULL) {  r = t; return r;  }
    if (get_balance_factor(p) <= get_balance_factor(t))  p->right=t;
    else p->left=t;
	return r;
}

struct tree_node* turn_big_rev(struct tree_node* r, struct tree_node* p) 
{
    struct tree_node* t=r->right->left;
    r->right->left=t->right;
    t->right=r->right;
    r->right=t->left;
    t->left=r;
    
    if(p==NULL) {r = t; return r;}
    if(get_balance_factor(p) <= get_balance_factor(t))p->right=t;
    else p->left=t;
	return r;
}



struct tree_node* tree_balancing(struct tree_node* r, struct tree_node* p) // БАЛАНСИРОВКА МЕРТВА
{
	struct tree_node* rem = r; // --??
	
	if (r)
	{
	    //struct tree_node* buff;
		
		if ((node_height(r->left) - node_height(r->right)) == 2)
		{
		    if (node_height(r->left->left) > node_height(r->left->right))  {  r = turn_min_on(r, p);  }
			else  {  r = turn_big_on(r, p);  }
		}
		if ((node_height(r->left) - node_height(r->right)) == -2)
		{
		    if (node_height(r->right->left) < node_height(r->right->right))  {  r = turn_min_rev(r, p);  }  else  {  r = turn_big_rev(r, p);  }
		}
		
		p = r;
		
		if (r->left)  {/*  while (r->left)  {  r->left = tree_balancing(r->left, r); //-----  }*/  }
		if (r->right) {/* while (r->right)  {  r->right = tree_balancing(r->right, r);  }		*/ }
	}
	
	return rem;   // <--- просядет
}



/**/


/*
//______________Реализация балансировки__________________
 
void tree::Balance()
{
    if(root!=NULL)Balance(root, NULL);//Проверка не пустое ли дерево, если нет то запуск балансировки с передачей  адреса корня
}

int tree::Balance(elem* r,elem* p)
{
    if(( height(r->left) - height(r->right) )==2) 
    {
        if(height(r->left->left)>height(r->left->right)) turn_m_on(r, p);//Запустить Малый поворот по часовой стрелке
        else turn_b_on(r, p);;//Запустить Большой поворот по часовой
    }
    if(( height(r->left) - height(r->right) )==-2) 
    {
        if(height(r->right->left)<height(r->right->right)) turn_m_op(r, p);//Запустить Малый поворот против часовой стрелке
        else turn_b_op(r, p);//Запустить Большой поворот против часовой
    }
    p=r;
    if(r->left!=NULL)
        do
        {
        }while(!Balance(r->left,p));
    if(r->right!=NULL)
        do
        {
 
        }while(!Balance(r->right,p));
    return 1;
}
void tree::turn_m_on(elem*r,elem*p)
{
    elem* t=r->left;//Запоминаем адрес левого элемента
    r->left=t->right;//направляем левый указатель текущего элемента на правого потомка его левого потомка
    t->right=r;//Направляем правый указатель левого потомка на текущий элемент
    
    if(p==NULL) {root = t; return;}
    if(p->info<=t->info)p->right=t;//напрявляем указатели предшествуюшего элемента на сбалансированую ветку.
    else p->left=t;
}
void tree::turn_m_op(elem*r,elem*p)
{
    elem* t=r->right;
    r->right=t->left;
    t->left=r;
    
    if(p==NULL) {root = t; return;}
    if(p->info<=t->info)p->right=t;
    else p->left=t;
}
void tree::turn_b_on(elem*r, elem*p)
{
    elem* t=r->left->right;
    r->left->right=t->left;
    t->left=r->left;
    r->left=t->right;
    t->right=r;
 
    if(p==NULL) {root = t; return;}
    if(p->info<=t->info)p->right=t;
    else p->left=t;
}
void tree::turn_b_op(elem*r, elem*p)
{
    elem* t=r->right->left;
    r->right->left=t->right;
    t->right=r->right;
    r->right=t->left;
    t->left=r;
    
    if(p==NULL) {root = t; return;}
    if(p->info<=t->info)p->right=t;
    else p->left=t;
}
*/
