Require Import Bool.

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






