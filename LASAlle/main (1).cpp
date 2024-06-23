
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//  Author: Alex Mathew


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include <string>
#include <sstream>
#include "slist.h"
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};

class Node { //node class
  public: 
    Airport data;
    Node* next;
    
Node(Airport data1) {
      this->data=data1;
      this->next=NULL;
    }
};

class LinkedList { //standard way to define linkedlist class
  public:
    Node* head;

    LinkedList() {
      this->head=NULL;
    }

  void insert(Airport *data) {
    Node *next = new Node (*data);
    if (head == NULL){
      head=next;
      return;
    }

    Node * f = head;
    while (f->next!=NULL){
      f = f->next;
   }

   f->next = next;
  }
};

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}

double distanceToAustin(double lat1d, double lon1d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(-97.66989899);
  lon2r = deg2rad(30.19449997);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  double first = pow(sin(u/2), 2) + pow(sin(v/2), 2) * cos(lat1r) * cos(lat2r);
  return 2.0 * asin(sqrt(first)) * earthRadiusKm;
}

void simpleSortTotal(LinkedList *x) {
  if (x->head == nullptr) {
    return;
  }
  Node *nodeTemp = x->head;
  while (nodeTemp->next != NULL) {
    Node *nodeTemp2 = nodeTemp->next;
    while (nodeTemp2 != NULL) {
      if (distanceToAustin(nodeTemp->data.latitude, nodeTemp->data.longitude) > distanceToAustin(nodeTemp2->data.latitude, nodeTemp2->data.longitude)) {
        swap(nodeTemp->data, nodeTemp2->data);
       }
      nodeTemp2 = nodeTemp2->next;
     }
    nodeTemp = nodeTemp->next;
 }
}  

//void simpleSortTotal(Airport* s[], int c);
//double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
//double distanceToAustin(double lat1d, double lon1d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[20] ;
    Airport* airportArr[22343];			// Replace array with Linked List
    int airportCount = -1;
    //Airport* a[13500];
    
    infile.open ("airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            char array[999]; //idk
            airportArr[c] = new Airport();
            infile.getline(airportArr[c]->code, 256, ',');
            infile.getline(array, 256, ',');
            infile.getline(array, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr[c]->longitude = std::atof(cNum);
            infile.getline(cNum, 256, ',');
            airportArr[c]->latitude = std::atof(cNum);
            infile.getline(array, 256);

            /*if (!(c % 1000))
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;

            
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
            airportCount++;
        }
        infile.close();


            /*if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }*/
    LinkedList * LASAlle = new LinkedList();

    for (int i = 0; i < airportCount; i++) {
      LASAlle->insert(airportArr[i]);
    }

    simpleSortTotal(LASAlle);
    Node *var = LASAlle->head;

    for (int i = 0; i < airportCount; i++) {
      cout << var->data.code << " distance to Austin: " << distanceToAustin(var->data.latitude, var->data.longitude) << endl;
      var = var->next;
    }
  
}
 
    else {
    cout << "File isn't open";
  }

}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}
