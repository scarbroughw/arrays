#include <stdio.h>
main()
{
      int unit1[] = {100,80,90,95,100,50,0,85,95,95,95,100,70,30,100,100,90,95,90,60,40};
      int unit2[] = {110,100,100,75,100,70,25,125,100,95,100,90,50,0,100,120,100,95,100,75,50};
      int unit3[] = {60,50,50,65,70,25,25,65,75,55,60,50,50,25,50,60,80,55,50,40,20};
      int unit1_sold[] = {90, 80, 80, 75, 78, 42, 0, 58, 90, 77, 91, 100, 65, 20, 90, 90, 68, 92, 55, 52, 27};
      int unit2_sold[] = {88, 90, 100, 45, 66, 55, 16, 112, 83, 90, 86, 82, 42, 0, 92, 116, 95, 90, 81, 64, 44};
      int unit3_sold[] = {54, 44, 50, 65, 70, 15, 20, 44, 63, 51, 53, 40, 44, 22, 51, 60, 70, 39, 49, 36, 15};
      int week[3],uSum1[]={0,0,0},uSum2[]={0,0,0},uSum3[]={0,0,0},i,c=0,j,x=0,y=7;
      float cost1[3],cost2[3],cost3[3],totalCost[]={0,0,0},completeCost,newPrice1,newPrice2, newPrice3,totalUnits1,totalUnits2,totalUnits3,dif1,dif2,dif3,soldtotal[]={0,0,0},notSold[]={0,0,0};
      for(j=0;j<3;j++){
          for(i=x;i<y;i++)
          {   
              uSum1[j]+= unit1[i];
              uSum2[j]+= unit2[i];
              uSum3[j]+= unit3[i];
              
              
              week[0]+= unit1[i] + unit2[i] + unit3[i];
              week[1]+= unit1[i] + unit2[i] + unit3[i];
              week[2]+= unit1[i] + unit2[i] + unit3[i];
          }
          cost1[j]= uSum1[j]*5.5;
          cost2[j]= uSum2[j]*7.5;
          cost3[j]= uSum3[j]*9;
          x+=7;
          y+=7;
          }
          
          c=0;  
          x=0; 
          totalCost[0] = cost1[0]+cost1[1]+cost1[2];
          totalCost[1] = cost2[0]+cost2[1]+cost2[2];
          totalCost[2] = cost3[0]+cost3[1]+cost3[2]; 
          completeCost = totalCost[0] + totalCost[1] + totalCost[2];
          
          for(i=0;i<21;i++)
          {
          		totalUnits1 += unit1[i];
          		totalUnits2 += unit2[i];
          		totalUnits3 += unit3[i];
          		soldtotal[0]+=unit1_sold[i];
          		soldtotal[1]+=unit2_sold[i];
          		soldtotal[2]+=unit3_sold[i];
		  }
		  newPrice1 = totalUnits1*8.25;
		  newPrice2 = totalUnits2*10.75;
		  newPrice3 = totalUnits3*13.25;
		  
		  notSold[0]= totalUnits1-soldtotal[0];
		  notSold[1]= totalUnits2-soldtotal[1];
		  notSold[2]= totalUnits3-soldtotal[2];
         
          
          //for(j=1;j<4;j++){  
            for(i=1;i<4;i++)
            {
                      y=x+1;
                      printf("Sum of unit 1, week %i is %i\n",y,uSum1[x]);
                      printf("Cost for unit 1, week %i is $%.2f\n\n",y, cost1[x]);
                      
                      printf("Sum of unit 2, week %i is %i\n",y,uSum2[x]);
                      printf("Cost for unit 2, week %i is $%.2f\n\n",y, cost2[x]);
                      
                      printf("Sum of unit 3, week %i is %i\n",y,uSum3[x]);
                      printf("Cost for unit 3, week %i is $%.2f\n\n",y, cost3[x]);
                      
                      x++;
            }
            printf("Total cost for unit 1 in all weeks is $%.2f\n", totalCost[0]);
            printf("Total cost for unit 2 in all weeks is $%.2f\n", totalCost[1]);
            printf("Total cost for unit 3 in all weeks is $%.2f\n", totalCost[2]);
            printf("Total cost for all units in all weeks is $%.2f\n\n",completeCost);
            if(totalCost[0]>newPrice1){
              		dif1=totalCost[0]-newPrice1;
              		printf("Unit 1 new price makes loss of $%.2f\n",dif1);
              	}
            if(totalCost[0]<newPrice1){
              		dif1=newPrice1 -totalCost[0];
              		printf("Unit 1 new price makes profit of $%.2f\n",dif1);
              	}
            if(totalCost[1]<newPrice2){
              		dif2=newPrice2 -totalCost[1];
              		printf("Unit 2 new price makes profit of $%.2f\n",dif2);
              	}
            if(totalCost[1]>newPrice2){
              		dif2=totalCost[1]-newPrice2;
              		printf("Unit 2 new price makes loss of $%.2f\n",dif2);
              	}
      		if(totalCost[2]>newPrice3){
      				dif3=totalCost[2]-newPrice3;
      				printf("Unit 3 new price makes loss of $%.2f\n\n",dif3);
			  }
			if(totalCost[2]<newPrice3){
      				dif3=newPrice3-totalCost[2];
      				printf("Unit 3 new price makes profit of $%.2f\n\n",dif3);
			  }
			x=0;
			for(i=0;i<3;i++)
			{
				x++;
				printf("Number of Unit %i not sold: %.0f\n",x,notSold[i]);
			}
      
      
      
      getch();     
}
