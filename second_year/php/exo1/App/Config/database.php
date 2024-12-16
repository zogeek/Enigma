<?php

namespace App\Config;
use \PDO;
class database
{
private string $host = 'localhost';
private string $dbname = 'cours_php';
private string $username = 'root';
private string $password = '';
private mixed $pdo;

    public function __construct()
    {
        $this->pdo = new PDO("mysql:host=$this->host;dbname=$this->dbname", $this->username, $this->password);
        $this->pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }

    public function connect(): mixed
    {
        $this->pdo = new PDO("mysql:host=$this->host;dbname=$this->dbname", $this->username, $this->password);
        return $this->pdo;
    }

    public function getHost(): string
    {
        return $this->host;
    }

    public function getDbname(): string
    {
        return $this->dbname;
    }

    public function getUsername(): string
    {
        return $this->username;
    }

    public function getPassword(): string
    {
        return $this->password;
    }

    public function getPdo(): mixed
    {
        return $this->pdo;
    }

    /**
     * @param string $host
     */
    public function setHost(string $host): void
    {
        $this->host = $host;
    }

    /**
     * @param string $dbname
     */
    public function setDbname(string $dbname): void
    {
        $this->dbname = $dbname;
    }

    /**
     * @param string $username
     */
    public function setUsername(string $username): void
    {
        $this->username = $username;
    }

    /**
     * @param string $password
     */
    public function setPassword(string $password): void
    {
        $this->password = $password;
    }

    /**
     * @param mixed $pdo
     */
    public function setPdo(mixed $pdo): void
    {
        $this->pdo = $pdo;
    }
}