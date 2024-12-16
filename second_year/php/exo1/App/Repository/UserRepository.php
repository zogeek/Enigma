<?php

namespace App\Repository;

use App\Config\database;
use App\Entity\Users;

class UserRepository
{
    private $db;
    public function __construct()
    {
        $this->db = (new database())->connect();
    }

    public function getUser(int $id): mixed
    {
        $stmt = $this->db->prepare('SELECT * FROM users WHERE id = :id');
        $stmt->execute(['id' => $id]);
        $data = $stmt->fetch(\PDO::FETCH_ASSOC);
        return $data ? new Users($data['name'], $data['email'], $data['id'], $data['password'], $data['photo'], $data['created_at']): null;
    }

    public function getUsers(): mixed
    {
        $stmt = $this->db->prepare('SELECT * FROM users');
        $users = [];
        while ($row = $stmt->fetch()) {
            $users[] = new Users($row['name'], $row['email'], $row['id'], $row['password'], $row['photo'], $row['created_at']);
        }
        return $users;
    }

    public function createUser(Users $user): void
    {
        $stmt = $this->db->prepare('INSERT INTO users(name, email, password, photo, created_at) VALUES(:name, :email, :password, :photo, :created_at)');
        $stmt->execute([
            'name' => $user->getName(),
            'email' => $user->getEmail(),
            'password' => $user->getPassword(),
            'photo' => $user->getPhoto(),
            'created_at' => $user->getCreatedAt()
        ]);
    }

    public function updateUser(Users $user): void
    {
        $stmt = $this->db->prepare('UPDATE users SET name = :name, email = :email, password = :password, photo = :photo, created_at = :created_at WHERE id = :id');
        $stmt->execute([
            'name' => $user->getName(),
            'email' => $user->getEmail(),
            'password' => $user->getPassword(),
            'photo' => $user->getPhoto(),
            'created_at' => $user->getCreatedAt(),
            'id' => $user->getId()
        ]);
    }

    public function deleteUser(int $id): void
    {
        $stmt = $this->db->prepare('DELETE FROM users WHERE id = :id');
        $stmt->execute(['id' => $id]);
    }
}