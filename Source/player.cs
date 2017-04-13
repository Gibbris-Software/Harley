class Player{
    private int hp;
    private int stamina;
    private int attack_strength;
    private int defence;
    private int weight;
    private int max_weight_load;

    private int tile_x;
    private int tile_y;
    private int battle_x;
    private int battle_y;

    private Ability ability;
    private SpecialAttack special_attack;


    public Player(){
        /* To be implemented. */
    }


    public void attack(){
        /* To be implemented. */
    }

    public void strike(){
        /* To be implemented. */
    }

    public void special(){
        /* To be implemented. */
    }

    public void block(){
        /* To be implemented. */
    }

    public void dealdamage(int damage){
        /* To be implemented. */
    }

    public int getHealth(){
        return hp;
    }

    public int getStamina(){
        return stamina;
    }

    public void startBattle(){
        /* To be implemented. */
    }
}