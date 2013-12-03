using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Web;
using System.Web.Services;
using System.Data.SqlClient;
// defines ConfigurationSettings class
using System.Configuration;
// defines SoapHeader base class
using System.Web.Services.Protocols;



namespace wsHotel
{
    /// <summary>
    /// Summary description for HotelService
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class HotelService : System.Web.Services.WebService
    {
        private wsHotel.Models.HotelTask HotelTask = new wsHotel.Models.HotelTask();


        [WebMethod]
        public System.Data.DataSet wsSelect_Hotel_byCompanyID1(int Company_ID, string sSort)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Hotel_byCompanyID1(Company_ID, sSort);
            return ds;

        }
        [WebMethod]
        public System.Data.DataSet wsSelect_Hotel_byCompanyID(int Company_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Hotel_byCompanyID(Company_ID);
            return ds;

        }
        [WebMethod]
        public System.Data.DataSet wsSelect_Hotel_byHotelName(int Company_ID, string Hotel_Name)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Hotel_byHotelName(Company_ID, Hotel_Name);
            return ds;

        }


        [WebMethod]
        public System.Data.DataSet wsSelect_Hotel_byHotelID(int Company_ID, int Hotel_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Hotel_byHotelID(Company_ID, Hotel_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomType_byHotelID(int Hotel_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomType_byHotelID(Hotel_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomType_byHotelID_withSorting(int Hotel_ID, string sSort)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomType_byHotelID_withSorting(Hotel_ID, sSort);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Rooms_byHotelID(int Hotel_ID, string sSort)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Rooms_byHotelID(Hotel_ID, sSort);
            return ds;

        }
        [WebMethod]
        public System.Data.DataSet wsSelect_Rooms_byRoomID(int Hotel_ID, string Room_Number)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Rooms_byRoomID(Hotel_ID, Room_Number);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Room_Assigning_ByDate(string Room_Hotel_ID, string CheckIn, string CheckOut)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Room_Assigning_ByDate(Room_Hotel_ID, CheckIn, CheckOut);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Rooms_Count_byRoomID(int Hotel_ID, int Room_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Rooms_Count_byRoomID(Hotel_ID, Room_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Rooms_byID(int ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Rooms_byID(ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_byRoomID(int Room_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomSchedule_byRoomID(Room_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomBookingSub_bySchedule_ID(int Schedule_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomBookingSub_bySchedule_ID(Schedule_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomBookSub_byBookSubID(int BSID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomBookSub_byBookSubID(BSID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Rooms_byRoom_ID(int Hotel_ID, int Room_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Rooms_byRoom_ID(Hotel_ID, Room_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomType_byRoomName(string RoomName)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomType_byRoomName(RoomName);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomType_byRoomNameHotelID(string RoomName, int Hotel_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomType_byRoomNameHotelID(RoomName, Hotel_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Paypal_byID(string BookingID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Paypal_byID(BookingID);
            return ds;

        }


        [WebMethod]
        public System.Data.DataSet wsSelect_RoomType_byRoomID(int Room_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomType_byRoomID(Room_ID);
            return ds;

        }


        [WebMethod]
        public System.Data.DataSet wsSelect_RoomTypeDetails_byRoomID(int Room_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomTypeDetails_byRoomID(Room_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSELECT_AgentRate_byUserID(string User_ID, int Room_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.SELECT_AgentRate_byUserID(User_ID, Room_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Room_Assigning_ByBookingID(string BookingID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Room_Assigning_ByBookingID(BookingID);
            return ds;

        }


        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_byHotelID_Date(int Company_ID, int Hotel_ID, int Room_ID, string Schedule_Date)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomSchedule_byHotelID_Date(Company_ID, Hotel_ID, Room_ID, Schedule_Date);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomAgentSchedule_byHotelID_Date_AgentIdentity(int Hotel_ID, int Room_ID, string Schedule_Date, int AgentIdentity)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomAgentSchedule_byHotelID_Date_AgentIdentity(Hotel_ID, Room_ID, Schedule_Date, AgentIdentity);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_byHotelID_Date_SName(int Hotel_ID, string Schedule_Date, string Schedule_Name)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomSchedule_byHotelID_Date_SName(Hotel_ID, Schedule_Date, Schedule_Name);
            return ds;

        }


        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_byScheduleID(int Schedule_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomSchedule_byScheduleID(Schedule_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomAgentSchedule_byScheduleID(int Schedule_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.SELECT_RoomAgentSchedule_byScheduleID(Schedule_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomScheduleAgent_byScheduleID(int Schedule_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomScheduleAgent_byScheduleID(Schedule_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_byGroupSID(string Schedule_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomSchedule_byGroupSID(Schedule_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_byAgentSID(string Schedule_ID, string User_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomSchedule_byAgentSID(Schedule_ID, User_ID);
            return ds;

        }


        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_bySearch(int Country_ID, int City_ID, int Room_Count, string FromDate, string ToDate, int Company_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomSchedule_bySearch(Country_ID, City_ID, Room_Count, FromDate, ToDate, Company_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomScheduleAgent_bySearch(int Country_ID, int City_ID, int Room_Count, string FromDate, string ToDate, int Company_ID, int Agent_UserIdentity)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomScheduleAgent_bySearch(Country_ID, City_ID, Room_Count, FromDate, ToDate, Company_ID, Agent_UserIdentity);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSELECT_Users_byUserIDPass(string UserID, string Password, string CompanyLoginName)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.SELECT_Users_byUserIDPass(UserID, Password, CompanyLoginName);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSELECT_Company_byUserID(string CompanyName)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.SELECT_Company_byUser(CompanyName);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Users_byCompanyID(int Company_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Users_byCompanyID(Company_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Users_Agent_byCompanyID(int Company_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Users_Agent_byCompanyID(Company_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Users_byUserID(string User_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Users_byUserID(User_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Country(int companyID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Country(companyID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Country_byCountryName(string countryName, int companyID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Country_byCountryName(countryName, companyID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_City()
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_City();
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_City_byCountryID(int countryID, int companyID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_City_ByCountryID(countryID, companyID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_CityCountry_Combination(int companyID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_CityCountry_Combination(companyID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_City_byCityCountryName(string cityName, string countryName, string couchDestinationName, int companyID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_City_byCityCountryName(countryName, cityName, couchDestinationName, companyID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_City_byCountryCityID(int countryID, int cityID, int companyID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_City_byCountryCityID(countryID, cityID, companyID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomBooking_byAdminSearch(int Hotel_ID, int Room_ID, string CFromDate, string CToDate,
            string RFromDate, string RToDate, string OFromDate, string OToDate, string Status, int Company_ID, 
            string Book_ID, string Customer_Name, string Room_Hotel_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomBooking_bySearch(Hotel_ID, Room_ID, CFromDate, CToDate,
                RFromDate, RToDate, OFromDate, OToDate, Status, Company_ID, "", Book_ID, Customer_Name, Room_Hotel_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_AvailableRooms_byRoom_ID_Date(int hotelID, int roomID,
            string checkInDate, string checkOutDate, int AID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_AvailableRooms_byRoom_ID_Date(hotelID, roomID, checkInDate, checkOutDate, AID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomBooking_bySearch(int Hotel_ID, int Room_ID, string CFromDate, string CToDate,
            string RFromDate, string RToDate, string OFromDate, string OToDate, string Status, int Company_ID, string User,
            string Book_ID, string Customer_Name, string Room_Hotel_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomBooking_bySearch(Hotel_ID, Room_ID, CFromDate, CToDate,
                RFromDate, RToDate, OFromDate, OToDate, Status, Company_ID, User, Book_ID, Customer_Name, Room_Hotel_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomBooking_MaxInvNo_byCompanyID(int Company_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomBooking_MaxInvNo_byCompanyID(Company_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomBookingSub_byBookingID(int Booking_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomBookingSub_byBookingID(Booking_ID);
            return ds;

        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Voucher_RoomBooking_byBID(int Book_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Voucher_RoomBooking_byBID(Book_ID);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Voucher_RoomBookingSub_byBidHid(int Book_ID, int Hotel_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Voucher_RoomBookingSub_byBidHid(Book_ID, Hotel_ID);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Receipt_byReceiptNo(int Receipt_No)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Receipt_byReceiptNo(Receipt_No);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Receipt_byInvoiceNo(string Invoice_No)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Receipt_byInvoiceNo(Invoice_No);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_AgentTransaction_byUserID(string User, string fromDate, string toDate, string status)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_AgentTransaction_byUserID(User, fromDate, toDate, status);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_AgentInvoice_byAInvoiceNo(string Invoice_No)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_AgentInvoice_byAInvoiceNo(Invoice_No);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_AgentInvoice_byUserIDStatus(string User, string Status)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_AgentInvoice_byUserIDStatus(User, Status);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Report_SalesReport(string CFromDate, string CToDate, string RFromDate, string RToDate, string Status, int Company_ID, string User, string Book_From, string Book_Type)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Report_SalesReport(CFromDate, CToDate, RFromDate, RToDate, Status, Company_ID, User, Book_From, Book_Type);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Report_RoomSalesSummary(string RFromDate, string RToDate, string Status, int Company_ID, string User, string Book_From, string Book_Type, int Hotel_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Report_RoomSalesSummary(RFromDate, RToDate, Status, Company_ID, User, Book_From, Book_Type, Hotel_ID);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomSchedule_byRoomID_Date(string RoomCount, string CheckIn, string CheckOut, string RoomID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.SELECT_RoomSchedule_byRoomID_Date(RoomCount, CheckIn, CheckOut, RoomID);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Room_Assigning_ByID(int id)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Room_Assigning_ByID(id);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Room_Assigning_ByRoomID(int decider, string Room_Hotel_ID, int Company_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Room_Assigning_ByRoomID(decider, Room_Hotel_ID, Company_ID);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_Members(string Email, string Password, int MemberID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_Members(Email, Password, MemberID);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_RoomBooking_byCreatedUser(string CreatedUser)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.Select_RoomBooking_byCreatedUser(CreatedUser);
            return ds;
        }

        [WebMethod]
        public System.Data.DataSet wsSelect_COMPANY_byCompanyID(string Company_ID)
        {
            System.Data.DataSet ds = new System.Data.DataSet();
            ds = HotelTask.SELECT_COMPANY_byCompanyID(Company_ID);
            return ds;
        }


        //------------------------- INSERT ONLY --------------------//
        [WebMethod]
        public int wsInsert_Country(string Country_Name, int companyID)
        {
            return HotelTask.Insert_Country(Country_Name, companyID);
        }

        [WebMethod]
        public int wsInsert_City(int Country_ID, string City_Name, string Coach_Destination_Name, int companyID)
        {
            return HotelTask.Insert_City(Country_ID, City_Name, Coach_Destination_Name, companyID);
        }

        [WebMethod]
        public int wsInsert_Hotel(string Hotel_Name, int Country_ID, int City_ID, int Hotel_Cat, string Hotel_Remark, string Hotel_Address, string Hotel_Contact, int Company_ID, string User)
        {

            int err = HotelTask.Insert_Hotel(Hotel_Name, Country_ID, City_ID, Hotel_Cat, Hotel_Remark, Hotel_Address, Hotel_Contact, Company_ID, User);
            return err;

        }

        [WebMethod]
        public int wsInsert_RoomType(string Room_Name, int Room_Pax, int Hotel_ID, int Total_Room, string Room_Remark, string User)
        {

            int err = HotelTask.Insert_RoomType(Room_Name, Room_Pax, Hotel_ID, Total_Room, Room_Remark, User);
            return err;

        }

        [WebMethod]
        public int wsInsert_OnlineLog(string subject, string detail)
        {

            int err = HotelTask.Insert_OnlineLog(subject, detail);
            return err;

        }


        [WebMethod]
        public int wsInsert_RoomType_Details(int Room_ID, string Room_Size, String Room_Desc, String Room_Features, String Room_IMG, string User)
        {

            int err = HotelTask.Insert_RoomType_Details(Room_ID, Room_Size, Room_Desc, Room_Features, Room_IMG, User);
            return err;

        }

        [WebMethod]
        public int wsInsert_Insert_Room_Assigning(string TourBooking_No, int Room_ID, string Room_Hotel_ID, string Check_In_Date, string Check_Out_Date, string Status, int SID, int uid, int BID)
        {

            int err = HotelTask.Insert_Room_Assigning(TourBooking_No, Room_ID, Room_Hotel_ID, Check_In_Date, Check_Out_Date, Status, SID, uid, BID);
            return err;

        }

        [WebMethod]
        public int wsInsert_Paypal(string Txn_ID, string payment_status, string receiver_email, string payment_gross, string settle_amount, string settle_currency, string TourBooking_No)
        {

            int err = HotelTask.Insert_Paypal(Txn_ID, payment_status, receiver_email, payment_gross, settle_amount, settle_currency, TourBooking_No);
            return err;

        }


        [WebMethod]
        public int wsInsert_Rooms(int Room_ID, int Hotel_ID)
        {

            int err = HotelTask.Insert_Rooms(Room_ID, Hotel_ID);
            return err;

        }
        [WebMethod]
        public int wsInsert_Rooms1(int Room_ID, int Hotel_ID, string Room_Number, string Desc)
        {

            int err = HotelTask.Insert_Rooms1(Room_ID, Hotel_ID, Room_Number, Desc);
            return err;

        }

        [WebMethod]
        public int wsInsert_Schedule(string Schedule_Name, string Schedule_Date, string Publish_Date, string Online_Date, int Room_ID, int Room_Count, decimal Rate, string Schedule_Remark, string User)
        {

            int err = HotelTask.Insert_Schedule(Schedule_Name, Schedule_Date, Publish_Date, Online_Date, Room_ID, Room_Count, Rate, Schedule_Remark, User);
            return err;

        }

        [WebMethod]
        public int wsInsert_AgentSchedule(string Schedule_Name, string Schedule_Date, string Publish_Date, string Online_Date, int Room_ID, int Room_Count, decimal Rate, string Schedule_Remark, string User, int Agent_UserIdentity, string Agent_User_ID)
        {

            int err = HotelTask.Insert_AgentSchedule(Schedule_Name, Schedule_Date, Publish_Date, Online_Date, Room_ID, Room_Count, Rate, Schedule_Remark, User, Agent_UserIdentity, Agent_User_ID);
            return err;

        }


        [WebMethod]
        public int wsINSERT_AgentRate(string User_ID, decimal Rate, int Room_ID, int Hotel_ID)
        {

            int err = HotelTask.INSERT_AgentRate(User_ID, Rate, Room_ID, Hotel_ID);
            return err;

        }



        [WebMethod]
        public int wsInsert_Schedule_byGenerate(int Schedule_ID, string Schedule_Date, string Publish_Date, string Online_Date, int Room_Count, decimal Rate, string User)
        {
            int err = HotelTask.Insert_Room_Schedule_byGenerate(Schedule_ID, Schedule_Date, Publish_Date, Online_Date, Room_Count, Rate, User);
            return err;
        }

        [WebMethod]
        public int wsInsert_Room_Booking(string TourBooking_No, string Invoice_No, string Payment_Status, string Book_From,
            string Customer_Name, string Customer_Contact, string Customer_IC, string Customer_CarNo, decimal Total_Room_Price,
            decimal Total_Deposit, string Book_Type, string Book_Remark, string Book_Status, string User, int Company_ID,
            string Voucher_No, string Booking_User_Email)
        {
            int BID = HotelTask.Insert_Room_Booking(TourBooking_No, Invoice_No, Payment_Status, Book_From, Customer_Name,
                Customer_Contact, Customer_IC, Customer_CarNo, Total_Room_Price, Total_Deposit, Book_Type, Book_Remark,
                Book_Status, User, Company_ID, Voucher_No, Booking_User_Email);
            return BID;
        }

        [WebMethod]
        public int wsInsert_Room_BookingSub(int Book_ID, int Schedule_ID, int Room_Count, decimal Rate, decimal Agent_Rate, string Room_Number, string User)
        {
            int err = HotelTask.Insert_Room_BookingSub(Book_ID, Schedule_ID, Room_Count, Rate, Agent_Rate, Room_Number, User);
            return err;
        }

        [WebMethod]
        public int wsInsert_Room_BookingSub_withoutOffsetRoomBalance(int Book_ID, int Schedule_ID, int Room_Count, decimal Rate, decimal Agent_Rate, string Room_Number, string User)
        {
            int err = HotelTask.Insert_Room_BookingSub_withoutOffsetRoomBalance(Book_ID, Schedule_ID, Room_Count, Rate, Agent_Rate, Room_Number, User);
            return err;
        }

        [WebMethod]
        public int wsInsert_Users(string User_ID, string User_Name, string User_Role, int User_Level, string User_Email, string User_Contact, string User_Remark, string User_Status, decimal Agent_Balance,
                    string Agent_AccountType, decimal Agent_Commission, string Agent_CommissionType, string Main_User_ID, int Company_ID, string User)
        {
            int err = HotelTask.Insert_Users(User_ID, User_Name, User_Role, User_Level, User_Email, User_Contact, User_Remark, User_Status, Agent_Balance,
                                                Agent_AccountType, Agent_Commission, Agent_CommissionType, Main_User_ID, Company_ID, User);
            return err;
        }

        [WebMethod]
        public int wsInsert_Receipt(string Invoice_No, int Company_ID, decimal Amount, string Payment_Method, string Payment_Ref)
        {
            int RID = HotelTask.Insert_Receipt(Invoice_No, Company_ID, Amount, Payment_Method, Payment_Ref);
            return RID;
        }

        [WebMethod]
        public int wsInsert_AgentInvoice(string TID, decimal SumAmount, string User)
        {
            int RID = HotelTask.Insert_AgentInvoice(TID, SumAmount, User);
            return RID;
        }

        [WebMethod]
        public int wsInsert_Members(string Email, string Password, string Name, string Contact, string NRIC, string Passport, string Address, string Country, string City, string Company_ID)
        {
            return HotelTask.Insert_Members(Email, Password, Name, Contact, NRIC, Passport, Address, Country, City, Company_ID);
        }

        //------------------------- UPDATE ONLY ---------------------
        [WebMethod]
        public int wsUpdate_Hotel_DeactiveHotel(int Hotel_ID, string User)
        {

            int err = HotelTask.Update_Hotel_DeactiveHotel(Hotel_ID, User);
            return err;

        }

        [WebMethod]
        public int wsUPDATE_Room_Assigning_byRoomCount(int RoomCount, int BID, int SID)
        {

            int err = HotelTask.UPDATE_Room_Assigning_byRoomCount(RoomCount, BID, SID);
            return err;

        }

        [WebMethod]
        public int wsUPDATE_RoomType_DeactiveRoom(int Room_ID, string User)
        {

            int err = HotelTask.UPDATE_RoomType_DeactiveRoom(Room_ID, User);
            return err;

        }

        [WebMethod]
        public int wsUPDATE_Paypal_ByID(string Txn_ID, string payment_status, string TourBooking_No)
        {

            int err = HotelTask.UPDATE_Paypal_ByID(Txn_ID, payment_status, TourBooking_No);
            return err;

        }
        [WebMethod]
        public int wsUPDATE_RoomsAvail_byID(int ID, int Availibility)
        {

            int err = HotelTask.UPDATE_RoomsAvail_byID(ID, Availibility);
            return err;

        }
        [WebMethod]
        public int wsUPDATE_Rooms_DeactiveRoom(int ID, string User)
        {

            int err = HotelTask.UPDATE_Rooms_DeactiveRoom(ID, User);
            return err;

        }

        [WebMethod]
        public int wsUPDATE_RoomSchedule_Deactive(int Schedule_ID, string User)
        {
            int err = HotelTask.UPDATE_RoomSchedule_Deactive(Schedule_ID, User);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_RoomLeft_byScheduleID(int Schedule_ID, int Room_Count)
        {
            int err = HotelTask.UPDATE_RoomLeft_byScheduleID(Schedule_ID, Room_Count);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_RoomBook_Cancel(int Book_ID, string User)
        {
            int err = HotelTask.UPDATE_RoomBook_Cancel(Book_ID, User);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_RoomBookingPaymentStatus_byBookID(int Book_ID, string PaymentStatus)
        {
            int err = HotelTask.UPDATE_RoomBookingPaymentStatus_byBookID(Book_ID, PaymentStatus);
            return err;
        }

        [WebMethod]
        public int wsUpdate_Hotel_byHotelID(int Hotel_ID, string Hotel_Name, int Country_ID, int City_ID, int Hotel_Cat, string Hotel_Remark, string Hotel_Address, string Hotel_Contact, string User)
        {

            int err = HotelTask.UPDATE_Hotel_byHotelID(Hotel_ID, Hotel_Name, Country_ID, City_ID, Hotel_Cat, Hotel_Remark, Hotel_Address, Hotel_Contact, User);
            return err;

        }

        [WebMethod]
        public int wsUPDATE_RoomType_byRoomID(int Room_ID, string Room_Name, int Room_Pax, string Room_Remark, int Total_Room, string User)
        {

            int err = HotelTask.UPDATE_RoomType_byRoomID(Room_ID, Room_Name, Room_Pax, Room_Remark, Total_Room, User);
            return err;

        }

        [WebMethod]
        public int wsUPDATE_RoomTypeDetails_byRoomID(int Room_ID, string Room_Size, String Room_Desc, String Room_Features, String Room_IMG, string User)
        {

            int err = HotelTask.UPDATE_RoomTypeDetails_byRoomID(Room_ID, Room_Size, Room_Desc, Room_Features, Room_IMG, User);
            return err;

        }

        [WebMethod]
        public int wsUPDATE_Rooms_byID(int ID, string Room_Number, int Hotel_ID, int Room_ID, string Desc, string User)
        {

            int err = HotelTask.UPDATE_Rooms_byID(ID, Room_Number, Hotel_ID, Room_ID, Desc, User);
            return err;

        }


        [WebMethod]
        public int wsUPDATE_RoomSchedule_byScheduleID(int Schedule_ID, string Schedule_Name, string Schedule_Date, string Publish_Date, string Online_Date, int Room_ID, int Room_Count, decimal Rate, string Schedule_Remark, string User)
        {
            int err = HotelTask.UPDATE_RoomSchedule_byScheduleID(Schedule_ID, Schedule_Name, Schedule_Date, Publish_Date, Online_Date, Room_ID, Room_Count, Rate, Schedule_Remark, User);
            return err;
        }

        //, int Agent_UserIdentity, string Agent_User_ID
        [WebMethod]
        public int wsUPDATE_RoomScheduleAgent_byScheduleID(int Schedule_ID, string Schedule_Name, string Schedule_Date, string Publish_Date, string Online_Date, int Room_ID, int Room_Count, int Room_Left, decimal Rate, string Schedule_Remark, string User, int Agent_UserIdentity, string Agent_User_ID)
        {
            int err = HotelTask.UPDATE_RoomScheduleAgent_byScheduleID(Schedule_ID, Schedule_Name, Schedule_Date, Publish_Date, Online_Date, Room_ID, Room_Count, Room_Left, Rate, Schedule_Remark, User, Agent_UserIdentity, Agent_User_ID);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_RoomSchedule_byScheduleID_RoomCount(int Schedule_ID, int Room_Count)
        {
            int err = HotelTask.UPDATE_RoomSchedule_byScheduleID_RoomCount(Schedule_ID, Room_Count);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_AgentRate_byUserID(string User_ID, double Rate, int Room_ID)
        {
            int err = HotelTask.UPDATE_AgentRate_byUserID(User_ID, Rate, Room_ID);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_Country_byCountryID(int CountryID, string CountryName, string CountryStatus, int companyID)
        {
            return HotelTask.UPDATE_Country_byCountryID(CountryID, CountryName, CountryStatus, companyID);
        }

        [WebMethod]
        public int wsUPDATE_City_byCountryIDCityID(int CountryID, int CityID, string CityName, string CoachDestination, string CityStatus, int companyID)
        {
            return HotelTask.UPDATE_City_byCountryIDCityID(CountryID, CityID, CityName, CoachDestination, CityStatus, companyID);
        }

        [WebMethod]
        public int wsUPDATE_Room_Assigning(string TourBooking_No, int BID, string Room_Name)
        {
            int err = HotelTask.UPDATE_Room_Assigning(TourBooking_No, BID, Room_Name);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_Room_Assigning_withID(int id, string TourBooking_No, int BID, string Room_Name)
        {
            int err = HotelTask.UPDATE_Room_Assigning_withID(id, TourBooking_No, BID, Room_Name);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_Room_Assigning_DeactiveRoom(string TourBooking_No)
        {
            int err = HotelTask.UPDATE_Room_Assigning_DeactiveRoom(TourBooking_No);
            return err;
        }


        [WebMethod]
        public int wsUPDATE_RoomBook_byBookID(int Book_ID, string TourBooking_No, string Invoice_No, string Customer_Name, string Customer_Contact, string Customer_IC, string Customer_CarNo, decimal Total_Price, decimal Total_Deposit, string Book_Type, string Book_Remark, string Book_Status, string User, string PaymentStatus)
        {
            int BID = HotelTask.UPDATE_RoomBook_byBookID(Book_ID, TourBooking_No, Invoice_No, Customer_Name, Customer_Contact, Customer_IC, Customer_CarNo, Total_Price, Total_Deposit, Book_Type, Book_Remark, Book_Status, User, PaymentStatus);
            return BID;
        }

        [WebMethod]
        public int wsUPDATE_RoomBookSub_byBookSID(int Book_Sub_ID, decimal Rate, int Room_Count, string Room_Number, string User)
        {
            int err = HotelTask.UPDATE_RoomBookSub_byBookSID(Book_Sub_ID, Rate, Room_Count, Room_Number, User);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_RoomBookSub_setRoomNum_byBookID(int Book_ID, string Room_Number, string User)
        {
            int err = HotelTask.UPDATE_RoomBookSub_setRoomNum_byBookID(Book_ID, Room_Number, User);
            return err;
        }

        [WebMethod]
        public int wsUpdate_Users_byUserID(string User_ID, string User_Name, string User_Role, int User_Level, string User_Email, string User_Contact, string User_Remark, string User_Status, decimal Agent_Balance,
                    string Agent_AccountType, decimal Agent_Commission, string Agent_CommissionType, string Main_User_ID, string User)
        {
            int err = HotelTask.UPDATE_Users_byUserID(User_ID, User_Name, User_Role, User_Level, User_Email, User_Contact, User_Remark, User_Status, Agent_Balance,
                                                Agent_AccountType, Agent_Commission, Agent_CommissionType, Main_User_ID, User);
            return err;
        }

        [WebMethod]
        public int wsUpdate_Users_Password_byUserID(string User_ID, string Password, string User)
        {
            int err = HotelTask.UPDATE_Users_Password_byUserID(User_ID, Password, User);
            return err;
        }


        [WebMethod]
        public int wsUPDATE_Users_AgentBalance_byUserID(string User, decimal Amount, string Trans_Type, string Trans_Ref, string Invoice_No, string Admin)
        {
            int err = HotelTask.UPDATE_Users_AgentBalance_byUserID(User, Amount, Trans_Type, Trans_Ref, Invoice_No, Admin);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_Users_AgentBalanceMinus_byUserID(string User, decimal Amount, string Trans_Type, string Trans_Ref, string Invoice_No, string Admin)
        {
            int err = HotelTask.UPDATE_Users_AgentBalanceMinus_byUserID(User, Amount, Trans_Type, Trans_Ref, Invoice_No, Admin);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_Users_AgentBalance_UPDBOOK_byUserID(string User, decimal Amount, string Trans_Type, string Trans_Ref)
        {
            int err = HotelTask.UPDATE_Users_AgentBalance_UPDBOOK_byUserID(User, Amount, Trans_Type, Trans_Ref);
            return err;
        }

        [WebMethod]
        public int wsUPDATE_AgentInvoice_PAID_byUserID(string Invoice_No, string User)
        {
            int err = HotelTask.UPDATE_AgentInvoice_PAID_byUserID(Invoice_No, User);
            return err;
        }

        [WebMethod]
        public int wsUpdate_Members(string MemberID, string Password, string Name, string Contact, string NRIC, string Passport, string Address, string Country, string City)
        {
            return HotelTask.Update_Members(MemberID, Password, Name, Contact, NRIC, Passport, Address, Country, City);
        }

        [WebMethod]
        public int wsUpdate_ProcessBooking(string ProcessUser, int Book_ID)
        {
            return HotelTask.Update_ProcessBooking(ProcessUser, Book_ID);
        }

        /*
        [WebMethod]
        public System.Data.DataSet wsSELECT_Reference_No(int Hotel_ID, string Schedule_Date)
        {
            return HotelTask.SELECT_Reference_No(Hotel_ID, Schedule_Date);
        }
        */

        [WebMethod]
        public System.Data.DataSet wsSELECT_Reference_No_bySearch(int Company_ID, int Hotel_ID, string Schedule_Date_From, string Schedule_Date_To)
        {
            return HotelTask.SELECT_Reference_No_bySearch(Company_ID, Hotel_ID, Schedule_Date_From, Schedule_Date_To);
        }

        [WebMethod]
        public int wsINSERT_Reference_No(int Hotel_ID, string Schedule_Date, string Reference_No)
        {
            return HotelTask.INSERT_Reference_No(Hotel_ID, Schedule_Date, Reference_No);
        }

        [WebMethod]
        public int wsUPDATE_Reference_No(int Hotel_ID, string Schedule_Date, string Reference_No)
        {
            return HotelTask.UPDATE_Reference_No(Hotel_ID, Schedule_Date, Reference_No);
        }

        [WebMethod]
        public int wsUPDATE_CheckIn_Status(int Book_ID, char CheckIn_Status)
        {
            return HotelTask.UPDATE_CheckIn_Status(Book_ID, CheckIn_Status);
        }
    }
}
