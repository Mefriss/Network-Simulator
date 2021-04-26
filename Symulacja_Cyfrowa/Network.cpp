#include "Network.h"

#include <spdlog/spdlog.h>

#include "BTS.h"




void Network::Create_New_Bts()
{
	Bts_ = new BTS(15);// k = 15
}

int Network::Draw_User_Arival_Time(int Time_Elapsed)
{
	User_Arival_Time_ = Time_Elapsed + rand() % 10 + 1;
	//User_Arival_Times_.push(User_Arival_Time_);
	return User_Arival_Time_;
}

void Network::Add_New_User(User* New_User)
{
	User_List_.push(New_User);
}

void Network::Set_BTS_Data()
{
	Bts_->Set_Data();
	//Bts_->Set_Resource_Block_To_User();
}

void Network::Set_BTS_Error(int User_Id)
{
	
	Bts_->Set_Transmission_Succes_Flag(User_Id);
}

void Network::Set_Time_Until_New_User_Arives(int Time_Until_New_User_Arives)
{
	Time_Until_New_User_Arives_ = Time_Until_New_User_Arives;
}

void Network::Set_Time_Until_Bts_Assigns_Block(int Time_Until_Bts_Assigns_Block)
{
	Time_Until_Bts_Assigns_Block_ = Time_Until_Bts_Assigns_Block;
}

void Network::Set_Chanel_Busy_Flag(bool Channel_Busy)
{
	Channel_Busy_ = Channel_Busy;
}

void Network::Set_User_Data_To_Be_Fetched()
{
	User_List_.front()->Set_Data_To_Be_Fetched();
}


std::vector<int> Network::Map_Bts_Blocks(int Blocs_Per_User)
{
	return Bts_->Set_Resource_Block_To_User(Blocs_Per_User);
	
}

void Network::Map_Blocks_To_User()
{
	int Downloaded_Data = Bts_->Get_Resource_Block_Map().front();
	User_List_.front()->Set_User_Data(Downloaded_Data);
}

void Network::Send_Bts_Block(User* user)
{
	Bts_->Send_Block_To_User(15,User_List_.front()->Get_Bit_Rate_Vector(),user);
}

//float Network::Draw_Bitrate_Change_Time(float Tau)
//{
//	///return rand()%0.1 
//}

std::queue<User*> Network::Get_User_list()
{
	return User_List_;
}

bool Network::Check_Bts_Blocks_Depleted()
{
	return Bts_->Get_Blocks_Depleted_Flag();
}

int Network::Calculate_Block_Assingment_Time(int Time_Elapsed,int Assingmnet_Time_Step)
{
	Block_Assignment_Time_ = Time_Elapsed + Assingmnet_Time_Step -1;
	return Block_Assignment_Time_;
}

void Network::Remove_User()
{
	std::cout << "Usunięto użytkownika nr: " << User_List_.front()->Get_User_ID() << std::endl;
	spdlog::info("User has been removed from queue \n");
	User_List_.pop();
}

void Network::Grant_Blocks_To_User()
{
	User_List_.front()->Save_Blocks(Map_Bts_Blocks());
}

void Network::Generate_Packet_And_Add_New_User(int Id)
{
	
	User* New_User = new User(Id);
	New_User->Set_Data_To_Be_Fetched();
	User_List_.push(New_User);
}

void Network::Pop_Arival_Time()
{
	//User_Arival_Times_.pop();
}

