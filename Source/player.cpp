using System;

namespace Harley
{
	public class Player{
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


		public Player()
		{
			hp = 100;
			stamina = 100;
			attack_strength = 12;
			defence = 5;
			weight = 9;
			max_weight_load = 0;
			tile_x = 40;
			tile_y = 40;
			battle_x = 40;
			battle_y = 40;
			ability = new HealthRegenAbility ();
			special_attack = new SpecialAttack ();
		}


		public void Attack()
		{
			/* To be implemented. */
		}

		public void Strike()
		{
			/* To be implemented. */
		}

		public void Special()
		{
			/* To be implemented. */
		}

		public void Block()
		{
			/* To be implemented. */
		}

		public void DealDamage(int damage)
		{
			/* To be implemented. */
		}

		public int Health
		{
			get { return hp; }
		}

		public int Stamina
		{
			get { return stamina; }
		}

		public int BattleX
		{
			get { return battle_x; }
		}

		public int BattleY {
			get { return battle_y; }
		}

		public int TileX
		{
			get { return tile_x; }
		}

		public int TileY {
			get { return tile_y; }
		}

		public void StartBattle()
		{
			/* To be implemented. */
		}

		public void MoveRightBattle(int distance){
			battle_x += distance;
		}

		public void MoveLeftBattle(int distance){
			battle_x -= distance;
		}

		public void MoveUpBattle(int distance){
			battle_y -= distance;
		}

		public void MoveDownBattle(int distance){
			battle_y += distance;
		}

		public void MoveRightTile(int distance){
			tile_x += distance;
		}

		public void MoveLeftTile(int distance){
			tile_x -= distance;
		}

		public void MoveUpTile(int distance){
			tile_y -= distance;
		}

		public void MoveDownTile(int distance){
			tile_y += distance;
		}
	}
}