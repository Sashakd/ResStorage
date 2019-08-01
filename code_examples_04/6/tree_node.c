#include "tree_node.h"

void node_info(struct tree_node* node)
{
    printf("-----------------------------------------------------\n");
    if (node)
    {
        printf("node  == %s;\n", node->data);

        if (node->up)
            printf("up    == %s;\n", node->up->data);
        else
            printf("up    == (NULL);\n");

        if (node->left)
            printf("left  == %s;\n", node->left->data);
        else
            printf("left  == (NULL);\n");

        if (node->right)
            printf("right == %s;\n", node->right->data);
        else
            printf("right == (NULL);\n");

    }
    else
        printf("node == (NULL);\n");
    printf("-----------------------------------------------------\n");
}

struct tree_node* append_node(struct tree_node* root, const char form, char* temp)
{
    if ((form == 'C') || (form == 'L') || (form == 'R') || (form == 'M'))
	{
	    struct tree_node* buff;  buff = malloc(sizeof(struct tree_node));
	    
	    if (!buff)  {  printf("--failed -- out of memory\n");  return NULL;  }		
		
	    if (form == 'C')
		{
	        buff->data = temp;	 buff->left = NULL;  
			buff->right = NULL;  buff->up = NULL;
			
			return buff;	//strcpy(buff->data, temp);	
		}
		else
		if (form == 'L')
		{
			root->left = buff;   buff->data = temp;
			buff->right = NULL;  buff->left = NULL;	
            buff->up = root;	 root = root->left; 	
            
			return root;
		}
		else
		if (form == 'R')
		{
		    root->right = buff;  buff->data = temp;
		    buff->right = NULL;  buff->left = NULL;
			buff->up = root;     root = root->right;	
			
			return root;
		}
		else  if (form == 'M')  return NULL;  else  return NULL;
	}
	else  return NULL;
}

struct tree_node* add_tree_node(struct tree_node* root, char* temp)  
{	
    if (root == NULL)  {  struct tree_node* buff;  buff = append_node(NULL, 'C', temp);  return buff;  }  // создание корня
	else
    {
		struct tree_node* qur_root = root;
			
		while (qur_root)  
		{
            if (strcmp(qur_root->data, temp) < 0)  // меньше существующего ////////////////////////
			{
                if (!qur_root->left)
                    qur_root = append_node(qur_root, 'L', temp);
                else
                    qur_root = qur_root->left;	// левый
			}
			else
            if (strcmp(qur_root->data, temp) > 0)  // больше существующего ///////////////////////
			{
                if (!qur_root->right)
                    qur_root = append_node(qur_root, 'R', temp);
                else
                    qur_root = qur_root->right;  // правый
			}
			else  qur_root = append_node(qur_root, 'M', temp);
		}
			
		return root;
	}
}

struct tree_node* add_test_tree(void)  
{
    struct tree_node* root = NULL;
	struct tree_node* qur;
	
	root = add_tree_node(root, "tree");    qur = root;
	
	qur = add_tree_node(qur, "mind");	qur = add_tree_node(qur, "will");
	qur = add_tree_node(qur, "over");	qur = add_tree_node(qur, "pool");
	qur = add_tree_node(qur, "rune");   qur = add_tree_node(qur, "kick");
	
	return root;
}

struct tree_node* make_test_tree1(void)
{
    struct tree_node *root, *r_L, *r_R, *r_LL, *r_LR, *r_LLL, *r_RL, *r_RLR, *r_RR, *r_RRL, *r_RRR;
	
	root = malloc(sizeof(struct tree_node));  r_L = malloc(sizeof(struct tree_node));
	r_R = malloc(sizeof(struct tree_node));   r_LL = malloc(sizeof(struct tree_node));
	r_LR = malloc(sizeof(struct tree_node));  r_LLL = malloc(sizeof(struct tree_node));
	r_RL= malloc(sizeof(struct tree_node));   r_RLR = malloc(sizeof(struct tree_node));
	r_RR = malloc(sizeof(struct tree_node));  r_RRL = malloc(sizeof(struct tree_node));
	r_RRR = malloc(sizeof(struct tree_node));
	
	if (!((root)||(r_L)||(r_R)||(r_LL)||(r_LR)||(r_LLL)||(r_RL)||(r_RLR)||(r_RR)||(r_RRL)||(r_RRR)))
	    return NULL;
		
	root->data = "root";	root->left = r_L;	  root->right = r_R;      root->up = NULL;
	r_L->data = "r_L";	    r_L->left = r_LL;	  r_L->right = r_LR;      r_L->up = root;
	r_LL->data = "r_LL";	r_LL->left = r_LLL;	  r_LL->right = NULL;     r_LL->up = r_L;
	r_LLL->data = "r_LLL";	r_LLL->left = NULL;	  r_LLL->right = NULL;    r_LLL->up = r_LL;
	r_LR->data = "r_LR";	r_LR->left = NULL;	  r_LR->right = NULL;     r_LR->up = r_L;
	r_R->data = "r_R";      r_R->left = r_RL;     r_R->right = r_RR;      r_R->up = root;
	r_RL->data = "r_RL";    r_RL->left = NULL;    r_RL->right = r_RLR;    r_RL->up = r_R;
	r_RLR->data = "r_RLR";  r_RLR->left = NULL;   r_RLR->right = NULL;    r_RLR->up = r_RL;
	r_RR->data = "r_RR";    r_RR->left = r_RRL;   r_RR->right = r_RRR;    r_RR->up = r_R;
	r_RRL->data = "r_RRL";  r_RRL->left = NULL;   r_RRL->right = NULL;    r_RRL->up = r_RR;
	r_RRR->data = "r_RRR";  r_RRR->left = NULL;   r_RRR->right = NULL;    r_RRR->up = r_RR;	
    return root;
}

struct tree_node* print_tree_elements(struct tree_node* node)  // NULL - fail,  node - ok
{
    if (node)  printf("%s\n", node->data);  return node;
}

struct tree_node* search_tree_node(struct tree_node* root, char* ch)
{
    struct tree_node* node;
	
	if (root)
	{
        if ((root->right) || (root->left))
        {
            node = root;

            while (node)
            {
                //printf("searchung...\n");
                if (strcmp(ch, node->data) > 0)
                    node = node->left;
                else
                    if (strcmp(ch, node->data) < 0)
                        node = node->right;
                    else
                        return node;  // найдено, конец поиска
            }
        }
        else
        {
            if (strcmp(ch, root->data) == 0)
                return root;
            else
                return NULL;
        }
	}

    return NULL;
}

struct tree_node* search_ch_tree_node(struct tree_node* root, char* ch)
{
    struct tree_node* node;

    if (root)
    {
        if ((root->right) || (root->left))
        {
            node = root;

            while (node)
            {
                if (strncmp(ch, node->data, 1) > 0)  node = node->left;
                else  if (strncmp(ch, node->data, 1) < 0)  node = node->right;
                else  return node;  // найдено, конец поиска
            }

            return NULL;
        }
        else
        {
            if (strcmp(ch, root->data) == 0)
                return root;
            else
                return NULL;
        }
    }
    else  return NULL;
}

/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       До этого момента всё верно

       исправлять нужно то, что ниже
                                |
                                |
                                V
*/

/*
RL -- правое поддерево в левое
LR -- левое поддерево в правое
*/
struct tree_node* merge_tree(struct tree_node* up_tree, struct tree_node* down_tree, const char* form)  // функция слияния деревьев
{
    if ((strncmp(form, "RL", 2) == 0)||(strncmp(form, "LR", 2) == 0))
	{	
	    if (strncmp(form, "RL", 2) == 0)  // правый в левый 
        {
            struct tree_node* qur = up_tree;

            if (qur)
            {
                while (qur->right)
                    qur = qur->right;

                qur->right = down_tree;

                down_tree->up = qur;

                return up_tree;  // в крайний правый левого  // идём вправо до упора  // вставляем
            }
            else
                return NULL;  // up_tree / down_tree
		}
		else                              // левый в правый 
        {
            struct tree_node* qur = up_tree;

            if (qur)
            {
                while (qur->left)
                    qur = qur->left;

                qur->left = down_tree;

                down_tree->up = qur;

                return up_tree;  // в крайний левый правого  //идём влево до упора  // вставляем
            }
            else
                return NULL;// down_tree;
		}
	}
	else  return NULL;
}

struct tree_node* del_merge_tree_node(struct tree_node* node)
{
    struct tree_node *up = node->up;
    struct tree_node *left = node->left;
	struct tree_node *right = node->right; 
	
    //printf("substep 1\n");  printf("[%s]\n", node->data);
	free(node->data);  free(node);   
	
	if(up)
	{
        if (up->left == node)
	    {
            //printf("substep 2L\n");
            up->left = right;
            up->left->up = up;  // Может нужно if-условие?
            up->left = merge_tree(up->left, left, "LR");    // <---- // в правый вставить левый

		    return up->left;
	    }
	    else
	    {
            //printf("substep 2R\n");
            up->right = left;
            up->right->up = up;
            up->right = merge_tree(up->right, right, "RL"); // <---- // в левый вставить правый

	    	return up->right;
	    }
	}
    else
    {
        //printf("root del\n");

        merge_tree(right, left, "LR");  //LR -- левое поддерево в правое
        right->up = NULL;

        //printf("right = %s\n", right->data);
        //printf("left = %s\n", left->data);

        return right;
    }
   	
}

struct tree_node* go_up(struct tree_node* node)
{
    while (node->up)
    {
        //printf("MOVEen UP -- node: %s\n", node->data);
        node = node->up;
    }

    return node;
}

struct tree_node* del_root(struct tree_node* root)
{
    printf("ROOT DELETING\n");
    if ((root->right) || (root->left))
    {
        if ((root->right) && (root->left))
        {
            free(root->data);
            root->data = malloc(sizeof(char)*(strlen(root->right->data)+1));
            memmove(root->data, root->right->data, strlen(root->right->data)+1);

            struct tree_node* R = root->right->right;
            struct tree_node* L = root->right->left;

            if ((R) && (L))
            {
                free(root->right->data);
                free(root->right);
                root->right = R;
                R->up = root->right;

                // merge
                R = merge_tree(R, L, "LR");

                return root;
            }
            else
            if ((R) && (!L))
            {
                free(root->right->data);
                free(root->right);
                root->right = R;
                R->up = root->right;

                return root;
            }
            else
            if ((!R) && (L))
            {
                free(root->right->data);
                free(root->right);
                root->right = L;
                L->up = root->right;

                return root;
            }
            else
            {
                free(root->right->data);
                free(root->right);
                root->right = NULL;

                return root;
            }
        }
        else
        if ((root->right) && (!root->left))
        {
            struct tree_node* R = root->right->right;
            struct tree_node* L = root->right->left;

            //root->data = root->right->data;
            free(root->data);
            root->data = malloc(sizeof(char)*(strlen(root->right->data)+1));
            memmove(root->data, root->right->data, strlen(root->right->data)+1);

            free(root->right->data);
            free(root->right);

            root->right = R;
            if (R) R->up = root;

            root->left = L;
            if (L) L->up = root;

            root->up = NULL;

            return root;
        }
        else
        if ((!root->right) && (root->left))
        {
            struct tree_node* R = root->left->right;
            struct tree_node* L = root->left->left;

            //root->data = root->left->data;
            free(root->data);
            root->data = malloc(sizeof(char)*(strlen(root->left->data)+1));
            memmove(root->data, root->left->data, strlen(root->left->data)+1);

            free(root->left->data);
            free(root->left);

            root->left = L;
            if (L) L->up = root;

            root->right = R;
            if (R) R->up = root;

            root->up = NULL;

            return root;
        }
    }
    else
    {
        free(root->data);
        free(root);
        return NULL;
    }

    return NULL;
}

struct tree_node* del_tree_node(struct tree_node* node) // БАЗОВАЯ ФУНКЦИЯ УДАЛЕНИЯ
{
    if (node)
    {
        struct tree_node *prev = node->up;

        //printf("step 1\n");

        if (node->up)
        {
            if ((node->left == NULL)&&(node->right == NULL))
            {
                //printf("step 2a. leaf\n");
                //printf("[%s]\n", node->data);

                if (node->up->left == node)
                    node->up->left = NULL;
                else
                if (node->up->right == node)
                    node->up->right = NULL;

                free(node->data);
                free(node);

                struct tree_node *r;

                r = go_up(prev);

                return r;
            }
            else
            {
                if ((node->left != NULL)&&(node->right == NULL))
                {
                    //printf("step 2b. lefted\n");  // освобождаем левый
                    if (prev->left == node)  // если удаляемый элемент является корнем левого поддерева
                    {
                        //printf("NODE\n");
                        prev->left = node->left;
                        prev->left->up = prev;
                        free(node->data);
                        free(node);
                    }
                    else
                    {
                        prev->right = node->left;
                        prev->right->up = prev;
                        free(node->data);
                        free(node);
                    }

                    struct tree_node *r;

                    r = go_up(prev);
                    return r;
                }
                else
                if ((node->left == NULL)&&(node->right != NULL))
                {
                    //printf("step 2c. righted\n");  // освобождаем правый
                    if (prev->right == node)
                    {
                        prev->right = node->right;
                        prev->right->up = prev;
                        free(node->data);
                        free(node);
                    }
                    else
                    {
                        prev->left = node->right;
                        prev->left->up = prev;
                        free(node->data);
                        free(node);
                    }

                    struct tree_node *r;

                    r = go_up(prev);
                    return r;
                }
                else
                {  ///////////////////////////////// если есть правое и левое поддерево
                    //printf("step 2d. fulled A\n");
                    node = del_merge_tree_node(node);
                    //printf("almoust");

                    struct tree_node *r;

                    r = go_up(node);
                    //printf("well\n");
                    return r;
                }

                return NULL;
            }
        }
        else
        {
            node = del_root(node);

            return node;
        }
    }
    else
        return NULL;
}

struct tree_node* DeleteNode(struct tree_node* node, char* val)
{
    if(node == NULL)  return NULL;

    if(strncmp(val, node->data, 1) == 0)
    {

        struct tree_node* tmp;
        if(node->right == NULL)
            tmp = node->left;
        else
        {
            struct tree_node* ptr = node->right;
            if(ptr->left == NULL)
            {
                ptr->left = node->left;
                ptr->left->up = ptr;
                tmp = ptr;
            }
            else
            {
                struct tree_node* pmin = ptr->left;

                while(pmin->left != NULL)
                {
                    ptr  = pmin;
                    pmin = ptr->left;
                }

                ptr->left   = pmin->right;
                ptr->left->up = ptr;
                pmin->left  = node->left;
                pmin->left->up = pmin;
                pmin->right = node->right;
                pmin->right->up = pmin;
                tmp = pmin;
            }
        }

        free(node->data);
        free(node);
        return tmp;
    }
    else if(strncmp(val, node->data, 1) < 0)
        node->left  = DeleteNode(node->left, val);
    else
        node->right = DeleteNode(node->right, val);

    return node;
}

void free_tree(struct tree_node* root)
{
    if ((root->right) || (root->left))
    {
        if (root->right)
            free_tree(root->right);

        if (root->left)
            free_tree(root->left);
    }

    free(root->data);
    free(root);
}

/// Функция печати в файл в виде сплошного текста
void print_text_tree(FILE* f, struct tree_node* root)
{
    if ((root->right) || (root->left))
    {
        if (root->right)
            print_text_tree(f, root->right);

        if (root->left)
            print_text_tree(f, root->left);
    }

    fprintf(f, "%s ", root->data);
}

// Обход дерева
void move_on(FILE* f, struct tree_node* root, const char* formation)
{
    if (strncmp("MLR", formation, 3) == 0) // сверху вниз: R,A,B   (префиксный обход)
    {
        if (root)
        {
            fprintf(f, "%s ", root->data);

            if ((root->right) || (root->left))
            {
                if (root->left)
                    move_on(f, root->left,  formation);

                if (root->right)
                    move_on(f, root->right, formation);
            }
        }
    }
    else
    if (strncmp("LMR", formation, 3) == 0) // слева направо: A,R,B   (инфиксный обход)
    {
        if (root) ////////////////////////////////////////////////////////////////
        {
            if ((root->right) || (root->left))
            {
                if (root->left)
                    move_on(f, root->left,  formation);

                fprintf(f, "%s ", root->data);

                if (root->right)
                    move_on(f, root->right, formation);
            }
            else
                fprintf(f, "%s ", root->data);
        }        ////////////////////////////////////////////////////////////////
    }
    else
    if (strncmp("LRM", formation, 3) == 0) // снизу вверх: A,B,R   (постфиксный обход)
    {
        if ((root->right) || (root->left))
        {
            if (root->left)
                move_on(f, root->left,  formation);

            if (root->right)
                move_on(f, root->right, formation);
        }

        fprintf(f, "%s ", root->data);
    }
}

