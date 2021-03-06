#ifndef Symulacja_Cyfrowa_Symulacja_Cyfrowa_User_H_
#define Symulacja_Cyfrowa_Symulacja_Cyfrowa_User_H_

#pragma once
#include <vector>
//#include "BTS.h"
#include <iostream>

#include "RNG.h"

class User
{
public:
	
	struct Resource_Blocks_;
	//std::vector<int>Get_Bit_Rate();

	User(bool Early_Phase_User, int User_ID, int Resource_Block_Count, bool rng, int Data);
	~User();
	
	void Save_Blocks(std::vector<int>Recived_Blocks);
	int Draw_Data_To_Be_Fetched();
	//float Draw_Bit_Rate_Table();
	//void Draw_Bit_Rate();
	int Draw_New_Bit_Rate(bool rng);
	void Aquire_Resource_Blocks(Resource_Blocks_ Resource_Block);
	void Pop_Bit_Rate_Vector();
	// GETTERS //
	int Get_User_ID();
	//int Get_Data_To_Be_Fetched() { return User_Data_; }
	std::vector<int> Get_Bit_Rate_Vector() { return Bit_Rate_; }
	int Get_User_Data() { return User_Data_; }
	int Get_Assigneed_Blocks_Count() { return Assigned_Blocks_; }
	bool Get_Early_Phase_Flag() { return Early_Phase_User_; }
	// SETTERS //
	void Subtract_User_Data(int Data_Fetched);
	void Update_Amount_Of_Recived_Resource_Blocks();
	void Set_Amount_Of_Recived_Resource_Blocks(int blocks = 3);
	void Set_Bit_Rate();
	void Set_Data_To_Be_Fetched();
	void Push_New_Bitrtate(int Bitrate);
	void Update_Bit_Rate(bool rng, int Bit_Rate);

private:

	bool Early_Phase_User_ = true;
	int User_Data_;
	int Assigned_Blocks_ = 3;
	int User_ID_;
	//RNG* Rng_;
	std::vector<int>Bit_Rate_;////Przepływność - r,k – zmienna losowa o rozkładzie jednostajnym w przedziale <20, 800> kbit/s
	//std::vector<Resource_Blocks_>Recived_Blocks_;
	
};

#endif //Symulacja_Cyfrowa_Symulacja_Cyfrowa_User_H_