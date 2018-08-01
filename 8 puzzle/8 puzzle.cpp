#include<iostream>
#include<queue>
using namespace std;


const int goal[][3]= {{1,2,3},{8,6,0},{7,5,4}};
int count=1;

struct point
{
    int x;
    int y;
};
struct s
{

    int puzzle[3][3];
    point last_p;

};
queue<s> q;

void display(s initial);

bool check(s initial);
bool check_point(point p1,point p2);

s find_the_goal (s initial);
point find_point(s initial);

s move_up(s initial);
s move_down(s initial);
s move_left(s initial);
s move_right(s initial);


int main()
{
    s initial;
    initial.puzzle[0][0]=1;
    initial.puzzle[0][1]=2;
    initial.puzzle[0][2]=3;
    initial.puzzle[1][0]=8;
    initial.puzzle[1][1]=0;
    initial.puzzle[1][2]=4;
    initial.puzzle[2][0]=7;
    initial.puzzle[2][1]=6;
    initial.puzzle[2][2]=5;

    initial.last_p.x=10;
    initial.last_p.y=10;

    cout<<"initial state:-\n";
    display(initial);
    s target =find_the_goal(initial);

    display(target);





}


//end main



void display(s initial)
{
    cout<<"------------"<<count<<"-------------------\n";
    for(int i=0; i<3 ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            cout<< initial.puzzle[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n";

}


bool check(s initial)
{
count++;
    for(int i=0; i<3 ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            if(initial.puzzle[i][j]!=goal[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

point find_point(s initial)
{
    point p;
    for(int i=0; i<3 ; i++)
    {
        for(int j=0; j<3 ; j++)
        {
            if(initial.puzzle[i][j]==0)
            {
                p.x=j;
                p.y=i;
                return p;
            }
        }
    }
    return p;
}
bool check_point(point p1,point p2)
{
    if(p1.x==p2.x&&p1.y==p2.y)
        return true;
    return false;
}

s move_up(s initial)
{
    point p1 = find_point(initial);
    point p2=p1;
    p2.y--;
    swap(initial.puzzle[p1.y][p1.x],initial.puzzle[p2.y][p2.x]);
    return initial;
}
s move_down(s initial)
{
    point p1 = find_point(initial);
    point p2=p1;
    p2.y++;
    swap(initial.puzzle[p1.y][p1.x],initial.puzzle[p2.y][p2.x]);
    return initial;
}
s move_left(s initial)
{
    point p1 = find_point(initial);
    point p2=p1;
    p2.x--;
    swap(initial.puzzle[p1.y][p1.x],initial.puzzle[p2.y][p2.x]);
    return initial;
}
s move_right(s initial)
{
    point p1 = find_point(initial);
    point p2=p1;
    p2.x++;
    swap(initial.puzzle[p1.y][p1.x],initial.puzzle[p2.y][p2.x]);
    return initial;
}


s find_the_goal (s initial)
{
cout<<"\n\n=============================== queue size: "<<q.size()<<" ===============================\n";
cout<<"=============================================================================\n";
display(initial);
cout<<"\n\n=============================================================================\n\n";

    point p;
    point last_p=initial.last_p;
    p=find_point(initial);
    s next=initial;
    s goal=initial;

    if(p.x==0&&p.y==0)
    {
        next=move_right(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {
            if(check(next))
            {
                return next;
            }

           q.push(next);display(next);
        }

        next=move_down(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;

    }
    else if(p.x==1&&p.y==0)
    {
        next=move_right(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {
            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }

        next=move_left(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_down(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;

    }
    else if(p.x==2&&p.y==0)
    {
        next=move_left(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_down(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;
    }
    else if(p.x==0&&p.y==1)
    {
        next=move_right(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_up(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_down(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;
    }
    else if(p.x==1&&p.y==1)
    {
        next=move_right(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_up(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_left(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_down(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;

    }
    else if(p.x==2&&p.y==1)
    {
        next=move_up(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_left(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }

        next=move_down(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;
    }
    else if(p.x==0&&p.y==2)
    {
        next=move_right(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next=move_up(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;
    }
    else if(p.x==1&&p.y==2)
    {
        next=move_right(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }

        next=move_up(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }
        next=move_left(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;
    }
    else if(p.x==2&&p.y==2)
    {

        next=move_up(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }

        next=move_left(initial);
        next.last_p=p;
        if(!check_point(last_p,find_point(next)))
        {

            if(check(next))
            {
                return next;
            }
           q.push(next);display(next);
        }


        next= q.front();
        q.pop();
        goal=find_the_goal(next);
        return goal;

    }else
    {
        return initial;
    }

    return goal;



}
