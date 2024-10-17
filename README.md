<h2 align="center">CRUD C++ System with Graphic User Interface</h2> 
<br/>
<h3 align="center">A C++ CRUD Application with <code>WxWidgets</code> for GUI and <code>SOCI</code> for MySQL Queries</h3>

<br/><br/>

## Application Dependences 

- <a href="https://docs.wxwidgets.org/3.2/overview_install.html">WxWidgets</a>
- <a href="https://github.com/SOCI/soci/tree/master">SOCI</a>
- <a href="https://dev.mysql.com/downloads/connector/cpp/">MySQL Connector/C++</a> (soci dependence)
- <a href="https://dev.mysql.com/downloads/mysql/8.0.html">MySQL Community Server</a>

> [!WARNING]
> You need to change `db`, `name`, `password` and `host`, in `data::db::DAO::connection_string` (file `/data/include/DAO.h`) to match your own database created;
