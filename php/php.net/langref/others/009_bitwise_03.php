<?php

# BitwiseFlag.php

abstract class BitwiseFlag
{
  protected $flags;

  /*
   * Note: these functions are protected to prevent outside code
   * from falsely setting BITS. See how the extending class 'User'
   * handles this.
   *
   */
  protected function isFlagSet($flag)
  {
    return (($this->flags & $flag) == $flag);
  }

  protected function setFlag($flag, $value)
  {
    if($value)
    {
      $this->flags |= $flag;
    }
    else
    {
      $this->flags &= ~$flag;
    }
  }
}

class User extends BitwiseFlag
{
  const FLAG_REGISTERED = 1; // BIT #1 of $flags has the value 1
  const FLAG_ACTIVE = 2;     // BIT #2 of $flags has the value 2
  const FLAG_MEMBER = 4;     // BIT #3 of $flags has the value 4
  const FLAG_ADMIN = 8;      // BIT #4 of $flags has the value 8

  public function isRegistered(){
    return $this->isFlagSet(self::FLAG_REGISTERED);
  }

  public function isActive(){
    return $this->isFlagSet(self::FLAG_ACTIVE);
  }

  public function isMember(){
    return $this->isFlagSet(self::FLAG_MEMBER);
  }

  public function isAdmin(){
    return $this->isFlagSet(self::FLAG_ADMIN);
  }

  public function setRegistered($value){
    $this->setFlag(self::FLAG_REGISTERED, $value);
  }

  public function setActive($value){
    $this->setFlag(self::FLAG_ACTIVE, $value);
  }

  public function setMember($value){
    $this->setFlag(self::FLAG_MEMBER, $value);
  }

  public function setAdmin($value){
    $this->setFlag(self::FLAG_ADMIN, $value);
  }

  public function __toString(){
    return 'User [' .
      ($this->isRegistered() ? 'REGISTERED' : '') .
      ($this->isActive() ? ' ACTIVE' : '') .
      ($this->isMember() ? ' MEMBER' : '') .
      ($this->isAdmin() ? ' ADMIN' : '') .
    ']';
  }
}

$user = new User();
$user->setRegistered(true);
$user->setActive(true);
$user->setMember(true);
$user->setAdmin(true);

echo $user;  // outputs: User [REGISTERED ACTIVE MEMBER ADMIN]
