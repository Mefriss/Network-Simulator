#ifndef Symulacja_Cyfrowa_Symulacja_Cyfrowa_Network_H_
#define Symulacja_Cyfrowa_Symulacja_Cyfrowa_Network_H_

#pragma once
#include <vector>
#include <queue>
#include "User.h"
#include "BTS.h"
#include <random>
#include "RNG.h"
#include "Stats.h"

class Network
{
public:

	Network();
	
	void Create_New_Bts();
	int Draw_User_Arival_Time(int Time_Elapsed);
	void Add_New_User(User* New_User);

	bool Check_Bts_Blocks_Depleted();
	int Calculate_Block_Assingment_Time(int Time_Elapsed, int Assingmnet_Time_Step = 1);
	void Remove_User();
	void Generate_Packet_And_Add_New_User(bool Early_Phase_User,int Id,bool rng);
	void Pop_Arival_Time();
	std::vector<int> Map_Bts_Blocks(int Blocs_Per_User = 1);
	void Draw_New_Bit_Rate_For_The_First_User(User* user, bool rng);
	void Map_Blocks_To_User();
	void Send_Bts_Block(User* user);
	void Send_Resource_Block_To_User(User* user);
	float Draw_Bit_Rate_Change_Time(float Tau, bool rng);
	void Push_User_To_The_End_Of_The_Queue();
	void Free_Up_The_Resource_Blocks(User* user);
	void Free_Up_All_Of_The_Resource_Blocks();
	void Assign_User_To_Resource_Block(User* User, bool rng, Stats* Stats);
	void Bts_INIT();

	int Send_Data_To_User(User* user);

	void Draw_Bitrates_Table_For_User(User* user);

	/// GETTERS ///
	
	std::queue<User*> Get_User_list();
	int Get_User_Arival_Time() { return User_Arival_Time_; }
	int Get_First_User_Arival_Time() { return User_Arival_Times_.front(); }
	int Get_Block_Assingment_Time() { return Block_Assignment_Time_; }
	int Get_Time_Until_Bts_Assigns_Block() { return Time_Until_Bts_Assigns_Block_; }
	int Get_Time_Until_New_User_Arives() { return Time_Until_New_User_Arives_; }
	bool Get_Channel_Busy_Flag() { return Channel_Busy_; }
	int Get_First_User_ID();
	int Get_Data_From_User(User* user);
	float Get_Bit_Rate_Change_Time() { return Time_Until_New_Bit_Rate_Is_Being_Drawn_; }
	int Get_Resource_Block_Count_From_Bts() { return Bts_->Get_Resource_Block_Count(); }
	int Get_Bit_Rate_Temp() { return Bit_Rate_Temp; }
	//int Get_Temp_Data_To_Send_() { return  Temp_Data_To_Send_; }
	
	/// SETTERS ///
	
	void Set_BTS_Data(bool rng);
	void Set_BTS_Error(int User_Id);
	void Set_Time_Until_New_User_Arives(int Time_Until_New_User_Arives);
	void Set_Time_Until_Bts_Assigns_Block(int Time_Until_Bts_Assigns_Block);
	void Set_Bit_Rate_Change_Time(float Time_Until_New_Bit_Rate_Is_Being_Drawn);
	void Set_Chanel_Busy_Flag(bool Channel_Busy);
	void Set_User_Data_To_Be_Fetched();
	
	

private:

	RNG* Data_Generator_;
	RNG* Zero_And_One_Generator_;
	RNG* Bit_Rate_Time_Change_Generator_;
	RNG* Bit_Rate_Generator_;
	RNG* User_Arrival_Time_Generator_;
	//RNG* Rng_;
	std::vector<int>Seeds_;
	std::queue<User*> User_List_;
	std::queue<int> User_Arival_Times_;
	//std::queue<int> User_Arival_Times_;
	BTS* Bts_;
	//int User_Creation_Time
	int Bit_Rate_Temp;
	bool Channel_Busy_;
	float Time_Until_New_Bit_Rate_Is_Being_Drawn_;
	int User_Arival_Time_;
	int Time_Until_New_User_Arives_;
	int Block_Assignment_Time_;
	int Time_Until_Bts_Assigns_Block_;
	//int Temp_Data_To_Send_;
	//int Block_Assignment_Timer_;

};



#endif
