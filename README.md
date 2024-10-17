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
> You need to change `db`, `name`, `password` and `host`, in `data::db::DAO::connection_string` (file `/data/include/DAO.h`) to match your own database created.

After all that installed, just run CMAKE and build the application.

<br>

##  MySQL Database Details

The CRUD operations occur in a table, DESCRIBED: 

| Field | Type         | Null | Key | Default | Extra          |
|-------|--------------|------|-----|---------|----------------|
| id    | int          | NO   | PRI | NULL    | auto_increment |
| name  | varchar(255) | NO   |     | NULL    |                |
| cpf   | varchar(255) | YES  |     | NULL    |                |
| age   | int          | NO   |     | NULL    |                |

> [!TIP]
> MySQL Query to create that table:
> ```
> CREATE TABLE People(
>     id INT NOT NULL AUTO_INCREMENT,
>     name varchar(255) NOT NULL,
>     cpf varchar(255), age INT NOT NULL,
>     PRIMARY KEY (id)
> );
> ```
