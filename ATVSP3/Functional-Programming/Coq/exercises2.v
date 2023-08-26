From Coq Require Import List.

Require Import Bool Arith_base List.

Import ListNotations.

Print nat.

Inductive disj1 : Prop :=
| left : disj1
| right : disj1.

Definition or_bool (d1 d2 : bool) : bool :=
    match d1, d2 with
    | true , d2 => true
    | false , d2 => d2
    end.

Definition xor_bool (d1 d2 : bool) : bool :=
    match d1, d2 with
    | true, false => true
    | false, true => true
    | true, true => false
    | false, false => false
    end.


Definition and_bool (b1 b2 : bool) : bool :=
    match b1 , b2 with
    | true  , b2 => b2
    | false , b2 => false
    end.

Lemma and_true_left : forall b, and_bool true b = b.
Proof.
    intros H1.
    destruct H1.
    +
    simpl.
    reflexivity.
    +
    simpl.
    reflexivity.
Qed.

Lemma and_false_left : forall b, and_bool false b = false.
Proof.
    intros H1.
    destruct H1.
    +
    simpl.
    reflexivity.
    +
    simpl.
    reflexivity.
Qed.

Lemma and_com : forall b b', and_bool b b' = and_bool b' b.
Proof.
    intros H1.
    destruct H1.
    +
    intros h1.
    destruct h1.
    -
    simpl.
    reflexivity.
    -
    simpl.
    reflexivity.
    +
    intros h2.
    destruct h2.
    -
    simpl.
    reflexivity.
    -
    simpl.
    reflexivity.
Qed.

Lemma and_assocc : forall b1 b2 b3, and_bool b1 (and_bool b2 b3) = and_bool (and_bool b1 b2) b3.
Proof.
    intros H1.
    destruct H1.
    +
    intros h1;intros h2.
    destruct h1; destruct h2.
    -
    simpl;reflexivity.
    -
    simpl;reflexivity.
    -
    simpl;reflexivity.
    -
    simpl;reflexivity.
    +
    intros h3;intros h4.
    destruct h3;destruct h4.
    *
    simpl;reflexivity.
    *
    simpl;reflexivity.
    *
    simpl;reflexivity.
    *
    simpl;reflexivity.
Qed.


Inductive nat : Set :=
| O : nat
| S : nat -> nat.

Fixpoint add (n m : nat) : nat :=
    match n with
    | O    => m
    | S n' => S (add n' m)
    end.


    Lemma zero_identity_add_left : forall n, 0 + n = n.
Proof.
    intro n.
    simpl.
    reflexivity.
Qed.

Lemma add_associative : forall n m p, n + (m + p) = (n + m) + p.
Proof.
    intros n m p.
    induction n as [| N IHn].
    +
    simpl.
    reflexivity.
    +
    simpl.
    auto.
Qed.

Require Import Coq.Init.Datatypes.
Require Import Coq.Bool.Bool.

Lemma add_inc : forall m n, S (m + n) = m + S n.
    Proof.
      intros m n.
      induction m as [ | m' IHm'].
      +
        simpl.
        reflexivity.
      +
        simpl.
        rewrite IHm'.
        reflexivity.
    Qed.

    Lemma zero_identity_add_right : forall n, n + 0 = n.
    Proof.
      intro n.
      induction n as [ | n' IHn'].
      +
        simpl.
        reflexivity.
      +
        simpl.
        rewrite IHn'.
        reflexivity.
    Qed.

    Lemma add_commut : forall n m, n + m = m + n.
    Proof.
      intros n m.
      induction n as [| n' IHn'].
      +
        simpl.
        symmetry.
        apply zero_identity_add_right.
      +
        simpl.
        rewrite IHn'.
        apply add_inc.
    Qed.

Fixpoint even_bool (n : nat) : bool :=
    match n with
    | 0 => true
    | 1 => false
    | S (S m) => even_bool m
    end.


Lemma even_add_n : forall n, even_bool (n + n) = true.
Proof.
    intros n.
    induction n as [| n' IHn'].
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite <- add_inc.
    apply IHn'.
Qed.
 

Fixpoint odd_bool (n : nat) : bool :=
    match n with
    | 0 => false
    | 1 => true
    | S (S m) => odd_bool m
    end.

Lemma odd_add_n_Sn : forall n, odd_bool (n + S n) = true.
Proof.
    intros n.
    induction n as [| n' IHn'].
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite <- add_inc.
    apply IHn'.
Qed.

Lemma even_SS : forall n, even_bool n = even_bool (S (S n)).
Proof.
    intros n.
    induction n as [| n' IHn'].
    +
    simpl.
    reflexivity.
    +
    simpl.
    reflexivity.
Qed.

Lemma odd_SS : forall n, odd_bool n = odd_bool (S (S n)).
Proof.
    intros n.
    induction n as [| n' IHn'].
    +
    simpl.
    reflexivity.
    +
    simpl.
    reflexivity.
Qed.

Definition not_bool (b : bool) : bool :=
    match b with
    | false => true
    | true  => false
    end.


(*Lemma even_bool_S : forall n, even_bool n = not_bool (even_bool (S n)).
Proof.
    intros n.
    induction n as [| n' IHn'].
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite -> IHn'.
    simpl.*)

Inductive list (A : Type) : Type :=
| nil : list A
| cons : A -> list A -> list A.

Require Import List.

Definition list1 : list nat := 1 :: 2 :: 3 :: nil.
Definition list2 : list nat := [1 ; 2 ; 3].

Fixpoint repeat {A : Type}(n : nat)(x : A) : list A :=
      match n with
      | O => []
      | S n' => x :: repeat n' x
      end.

Fixpoint length {A : Type}(xs : list A) : nat :=
    match xs with
    | []        => O
    | (x :: xs) => S (length xs)
    end.

Fixpoint app {A : Type}(xs ys : list A) : list A :=
    match xs with
    | []        => ys
    | (x :: xs) => x :: (app xs ys)
    end.

Fixpoint map {A B : Type}(f : A -> B)(xs : list A) : list B :=
    match xs with
    | []      => []
    | y :: ys =>  f y :: map f ys
    end.

Fixpoint reverse {A : Type}(xs : list A) : list A :=
    match xs with
    | [] => []
    | y :: ys => reverse ys ++ [ y ]
    end.

Lemma repeat_length {A : Type} : forall (n : nat)(x : A), length (repeat n x) = n.
Proof.
    intros n x.
    induction n as [| n' IHn'].
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite IHn'.
    reflexivity.
Qed.

Lemma app_nil_right {A : Type} : forall (xs : list A), xs ++ [] = xs.
Proof.
    intros xs.
    induction xs.
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite IHxs.
    reflexivity.
Qed.

Lemma app_assoc {A : Type} : forall (xs ys zs : list A), xs ++ (ys ++ zs) = (xs ++ ys) ++ zs.
Proof.
    intros xs ys zs.
    induction xs.
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite IHxs.
    reflexivity.
Qed.

Lemma map_app {A B : Type}{f : A -> B}
      : forall xs ys, map f (xs ++ ys) = map f xs ++ map f ys.
Proof.
    intros xs ys.
    induction xs.
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite IHxs.
    reflexivity.
Qed.

Lemma reverse_app {A : Type}
      : forall (xs ys : list A), reverse (xs ++ ys) = reverse ys ++ reverse xs.
Proof.
    intros xs ys.
    induction xs.
    +
    simpl.
    rewrite app_nil_right.
    reflexivity.
    +
    simpl.
    rewrite IHxs.
    rewrite app_assoc.
    reflexivity.
Qed.

Lemma reverse_inv {A : Type}
      : forall (xs : list A), reverse (reverse xs) = xs.
Proof.
    intros xs.
    induction xs.
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite <- IHxs.
    rewrite reverse_app.
    simpl.
    rewrite IHxs.
    rewrite IHxs.
    reflexivity.
Qed.

Inductive even : nat -> Prop :=
| ev_zero : even 0
| ev_ss   : forall n, even n -> even (S (S n)).

Definition double (n : nat) := 2 * n.

Lemma add_n : forall n, (n + n) = 2 * n.
Proof.
    intros n.
    induction n.
    +
    simpl.
    reflexivity.
    +
    simpl.
    rewrite add_inc.
    rewrite zero_identity_add_right.
    rewrite add_inc.
    reflexivity.
Qed.


Lemma double_even : forall n, even (double n).
Proof.
    intros n.
    induction n.
    +
    apply ev_zero.
    +
    unfold double.
    simpl.
    rewrite zero_identity_add_right.
    rewrite add_inc.
    rewrite add_commut.
    simpl.
    apply ev_ss.
    unfold double in IHn.
    rewrite add_n.
    apply IHn.
Qed.


Lemma one_not_even : ~ even 1.
Proof.
    intros Hone.
    inversion Hone.
Qed.

Lemma even_2_inv : forall n, even (2 + n) -> even n.
Proof.
    intros n H.
    inversion H.
    assumption.
Qed.



     







    
    
    

    



