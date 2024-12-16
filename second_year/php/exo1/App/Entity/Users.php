<?php

namespace App\Entity;
class Users
{
    public string $name;
    public int $id;
    public string $email;
    public string $password;
    public string $photo;
    public mixed $created_at;
    public mixed $last_login;

    public function __construct(string $name, string $email, int $id, string $password, string $photo, mixed $created_at)
    {
        $this->name = $name;
        $this->email = $email;
        $this->id = $id;
        $this->password = $password;
        $this->photo = $photo;
        $this->created_at = $created_at;
    }

    public function displayInfo(): string
    {
        return $this->name . $this->email;
    }

    public function getName(): string
    {
        return $this->name;
    }

    public function getEmail(): string
    {
        return $this->email;
    }

    public function getId(): int
    {
        return $this->id;
    }

    public function getPassword(): string
    {
        return $this->password;
    }

    public function getPhoto(): string
    {
        return $this->photo;
    }

    public function getCreatedAt(): mixed
    {
        return $this->created_at;
    }

    public function getLastLogin(): mixed
    {
        return $this->last_login;
    }

    public function setName(string $name): void
    {
        $this->name = $name;
    }

    public function setEmail(string $email): void
    {
        $this->email = $email;
    }

    public function setId(int $id): void
    {
        $this->id = $id;
    }

    public function setPassword(string $password): void
    {
        $this->password = $password;
    }

    public function setPhoto(string $photo): void
    {
        $this->photo = $photo;
    }

    public function setCreatedAt(mixed $created_at): void
    {
        $this->created_at = $created_at;
    }

    public function setLastLogin(mixed $last_login): void
    {
        $this->last_login = $last_login;
    }

}